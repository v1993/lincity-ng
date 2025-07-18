/*
Copyright (C) 2005 Matthias Braun <matze@braunis.de>

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
 * @author Matthias Braun
 * @file Child.hpp
 */

#ifndef __CHILD_HPP__
#define __CHILD_HPP__

#include <memory>
#include <optional>
#include <vector>       // for vector

#include "Rect2D.hpp"   // for Rect2D
#include "Vector2.hpp"  // for Vector2

class Component;

/**
 * @class Child
 */
class Child
{
public:
    Child() {};
    // TODO: remove entirely
    explicit Child(Component* _component);
    explicit Child(std::unique_ptr<Component>&& _component);
    ~Child() = default;

    Child(const Child&) = delete;
    Child& operator=(const Child&) = delete;
    Child(Child&&) = default;
    Child& operator=(Child&&) = default;

    const std::unique_ptr<Component>& getComponent() const
    {
        return component;
    }

    std::unique_ptr<Component>& getComponent()
    {
        return component;
    }

    void setComponent(std::unique_ptr<Component>&& component);

    void enable(bool enabled);

    bool isEnabled() const
    {
        return enabled;
    }

    void setPos(const Vector2& position)
    {
        this->position = position;
    }

    const Vector2& getPos() const
    {
        return position;
    }

    bool inside(const Vector2& pos) const;

    void setClipRect(const std::optional<Rect2D>& rect)
    {
        clipRect = rect;
    }

    const std::optional<Rect2D>& getClipRect() {
        return clipRect;
    }

private:
    Vector2 position;
    bool enabled = false;
    std::optional<Rect2D> clipRect;
    std::unique_ptr<Component> component;
};

#endif

/** @file gui/Child.hpp */
