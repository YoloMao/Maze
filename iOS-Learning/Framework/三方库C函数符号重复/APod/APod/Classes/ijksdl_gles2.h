/*
 * Copyright (c) 2016 Bilibili
 * copyright (c) 2016 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef IJKSDL__IJKSDL_GLES2_H
#define IJKSDL__IJKSDL_GLES2_H

#ifdef __APPLE__
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>
#endif

typedef struct SDL_Class SDL_Class;
typedef struct SDL_VoutOverlay SDL_VoutOverlay;
typedef struct AVFrame AVFrame;
typedef struct SDL_VoutOverlay_Opaque SDL_VoutOverlay_Opaque;

struct SDL_VoutOverlay {
    int w; /**< Read-only */
    int h; /**< Read-only */
    uint32_t format; /**< Read-only */
    int planes; /**< Read-only */
//    uint16_t pitches[8];  /**< in bytes, Read-only */ //AV_NUM_DATA_POINTERS
//    uint8_t pixels[8]; /**< Read-write */ //AV_NUM_DATA_POINTERS
    
    uint16_t *pitches;  /**< in bytes, Read-only */
    uint8_t *pixels; /**< Read-write */

    int is_private;

    int sar_num;
    int sar_den;

    SDL_Class               *opaque_class;
    SDL_VoutOverlay_Opaque  *opaque;

    void    (*free_l)(SDL_VoutOverlay *overlay);
    int     (*lock)(SDL_VoutOverlay *overlay);
    int     (*unlock)(SDL_VoutOverlay *overlay);
    void    (*unref)(SDL_VoutOverlay *overlay);

    int     (*func_fill_frame)(SDL_VoutOverlay *overlay, const AVFrame *frame);
};

/*
 * Common
 */

#ifdef DEBUG
#define IJK_GLES2_checkError_TRACE(op)
#define IJK_GLES2_checkError_DEBUG(op)
#else
#define IJK_GLES2_checkError_TRACE(op) IJK_GLES2_checkError(op) 
#define IJK_GLES2_checkError_DEBUG(op) IJK_GLES2_checkError(op)
#endif

void IJK_GLES2_checkError(const char *op);
GLuint IJK_GLES2_loadShader(GLenum shader_type, const char *shader_source);

/*
 * Renderer
 */
#define IJK_GLES2_MAX_PLANE 3
typedef struct IJK_GLES2_Renderer IJK_GLES2_Renderer;

void      IJK_GLES2_Renderer_free(IJK_GLES2_Renderer *renderer);

GLboolean IJK_GLES2_Renderer_setupGLES(void);
GLboolean IJK_GLES2_Renderer_isValid(IJK_GLES2_Renderer *renderer);
GLboolean IJK_GLES2_Renderer_isFormat(IJK_GLES2_Renderer *renderer, int format);
GLboolean IJK_GLES2_Renderer_use(IJK_GLES2_Renderer *renderer);
GLboolean IJK_GLES2_Renderer_renderOverlay(IJK_GLES2_Renderer *renderer, SDL_VoutOverlay *overlay);

#define IJK_GLES2_GRAVITY_RESIZE                (0) // Stretch to fill view bounds.
#define IJK_GLES2_GRAVITY_RESIZE_ASPECT         (1) // Preserve aspect ratio; fit within view bounds.
#define IJK_GLES2_GRAVITY_RESIZE_ASPECT_FILL    (2) // Preserve aspect ratio; fill view bounds.
GLboolean IJK_GLES2_Renderer_setGravity(IJK_GLES2_Renderer *renderer, int gravity, GLsizei view_width, GLsizei view_height);

#endif
