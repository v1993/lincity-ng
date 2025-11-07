/* ---------------------------------------------------------------------- *
 * src/gui/PainterSDL/TextureManagerSDL.cpp
 * This file is part of Lincity-NG.
 *
 * Copyright (C) 2005      Matthias Braun <matze@braunis.de>
 * Copyright (C) 2025      David Bears <dbear4q@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
** ---------------------------------------------------------------------- */

#include "TextureManagerSDL.hpp"

#include <SDL.h>           // for SDL_ConvertSurfaceFormat, SDL_FreeSurface
#include <SDL_video.h>
#include <stdexcept>

#include "TextureSDL.hpp"  // for TextureSDL

static const Uint8 ALPHA_BARRIER = 100;

TextureManagerSDL::TextureManagerSDL(SDL_Renderer *renderer)
  : renderer(renderer)
{
  SDL_RendererInfo info;
  if (SDL_GetRendererInfo(renderer, &info) != 0) {
    throw std::runtime_error(SDL_GetError());
  }
  SDL_Log("Renderer name: %s", info.name);
  if (SDL_strcmp(info.name, "opengl") == 0) {
    glTexParameteri = (PFNGLTEXPARAMETERIPROC) SDL_GL_GetProcAddress("glTexParameteri");
    glBlendFunc = (PFNGLBLENDFUNCPROC) SDL_GL_GetProcAddress("glBlendFunc");
  	// TODO: query OpenGL version
    glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) SDL_GL_GetProcAddress("glGenerateMipmap");
  }
}

TextureManagerSDL::~TextureManagerSDL()
{}

Texture *
TextureManagerSDL::create(SDL_Surface *image) {
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
  if(!texture) {
    throw std::runtime_error(SDL_GetError());
  }
  if (glGenerateMipmap && glTexParameteri && SDL_GL_BindTexture(texture, nullptr, nullptr) == 0) {
    SDL_SetTextureScaleMode(texture, SDL_ScaleModeLinear);
    SDL_Log("Generating mipmaps");
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
  }
  return new TextureSDL(texture);
}


/** @file gui/PainterSDL/TextureManagerSDL.cpp */
