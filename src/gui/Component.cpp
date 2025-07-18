/*
Copyright (C) 2005 Matthias Braun <matze@braunis.de>
Copyright (C) 2024 David Bears <dbear4q@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/**
 * @file Component.cpp
 * @author Matthias Braun
 */

#include <assert.h>     // for assert
#include <string.h>     // for strcmp, strncmp
#include <stdexcept>    // for runtime_error
#include <vector>       // for vector

#include "Component.hpp"
#include "Event.hpp"    // for Event
#include "Painter.hpp"  // for Painter

Component::Component() :
  parent(0), desktop(NULL), flags(0)
{
}

Component::~Component()
{
}

bool
Component::parseAttribute(const char* attribute, const char* value)
{
    if(strcmp(attribute, "name") == 0) {
        name = value;
        return true;
    } else if(strncmp(attribute, "xmlns", 5) == 0) { // can be ignored for now
        return true;
    }

    return false;
}

void
Component::drawChild(Child& child, Painter& painter)
{
    assert(child.getComponent());

    auto child_position = child.getPos();
    auto child_rect = child.getClipRect();

    if(child_rect) {
        painter.pushClipRect(*child_rect);
    }
    if(child_position != Vector2(0, 0)) {
        painter.pushTransform();
        painter.translate(child_position);
    }
    child.getComponent()->draw(painter);
    if(child_position != Vector2(0, 0)) {
        painter.popTransform();
    }
    if(child_rect) {
        painter.popClipRect();
    }
}

void
Component::draw(Painter& painter)
{
    for(auto& child: childs) {
        if(child.isEnabled())
            drawChild(child, painter);
    }
}

bool
Component::eventChild(Child& child, const Event& event, bool visible)
{
    assert(child.getComponent());

    Event ev = event;
    if(event.type == Event::MOUSEMOTION
        || event.type == Event::MOUSEBUTTONDOWN
        || event.type == Event::MOUSEBUTTONUP
        || event.type == Event::MOUSEWHEEL) {
        ev.mousepos -= child.getPos();
        if(visible && child.getComponent()->opaque(ev.mousepos))
            ev.inside = true;
        else
            ev.inside = false;
    }

    child.getComponent()->event(ev);
    return ev.inside;
}

void
Component::event(const Event& event) {
    bool visible = event.inside;
    for(auto& child: childs) {
        if(!child.isEnabled())
          continue;

        if(eventChild(child, event, visible))
            visible = false;
    }
}

void
Component::reLayout()
{
    if(getFlags() & FLAG_RESIZABLE) {
        resize(getWidth(), getHeight());
    }
}

Component*
Component::findComponent(const std::string& name)
{
    if(getName() == name)
        return this;

    for(auto& child: childs) {
        if (child.getComponent()) {
            Component* component = child.getComponent()->findComponent(name);
            if(component)
                return component;
        }
    }

    return 0;
}

Child *
Component::getParentChild() const {
  Component *p = getParent();
  if(!p) return NULL;
  for(Child& pc : p->childs)
    if(pc.getComponent().get() == this)
      return &pc;
  assert(false); // we must be a child of our parent
  return NULL;
}

Vector2
Component::relative2Global(const Vector2& pos)
{
    if(!parent)
        return pos;

    Child& me = parent->findChild(this);
    return parent->relative2Global(me.getPos() + pos);
}

Child&
Component::addChild(Component* component)
{
    assert(component->parent == nullptr);

    childs.emplace_back(component);
    component->parent = this;
    component->desktop = this->desktop;
    component->setDirty();
    return childs.back();
}

void
Component::resetChild(Child& child, Component* component)
{
    child.setComponent(std::unique_ptr<Component>{component});
    if(component != nullptr) {
        component->parent = this;
        component->desktop = this->desktop;
        component->setDirty();
        child.enable(true);
    }
}

void
Component::resize(float , float )
{
}

void
Component::setDirty(const Rect2D& rect)
{
    if(parent)
        parent->setChildDirty(this, rect);
}

Child&
Component::findChild(Component* component)
{
    for(auto& child: childs) {
        if(child.getComponent().get() == component)
            return child;
    }
    throw std::runtime_error("Child not found");
}

void
Component::setChildDirty(Component* childComponent, const Rect2D& area)
{
    for(auto& child: childs) {
        if(child.getComponent().get() != childComponent)
            continue;
        if(!child.isEnabled())
            return;
        Rect2D rect = area;
        rect.move(child.getPos());
        setDirty(rect);
        return;
    }

    assert(false);
}


/** @file gui/Component.cpp */
