/*
** EPITECH PROJECT, 2026
** WORKSHOP
** File description:
** Main int.c
*/
#include "../scene.h"
#include <CSFML/Config.h>
#include <CSFML/Graphics/RenderWindow.h>
#include <CSFML/Graphics/Types.h>
#include <CSFML/System/Vector2.h>
#include <CSFML/Window/Event.h>
#include <CSFML/Window/Keyboard.h>
#include <CSFML/Graphics/Texture.h>
#include <CSFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>

static void pause_events(scene_t *scene, sfRenderWindow *window, scene_id_t *current_scene)
{
    sfEvent evt;

    if (!scene || !window || !current_scene) {
        return;
    }
    while (sfRenderWindow_pollEvent(window, &evt)) {
        if (evt.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (evt.type == sfEvtKeyPressed) {
            if (evt.key.code == sfKeySpace) {
                *current_scene = GAME;
            } else if (evt.key.code == sfKeyEscape) {
                *current_scene = MENU;
            }
        }
    }
}

static void pause_update(scene_t *scene)
{
    if (!scene) {
        return;
    }
}

static void pause_render(scene_t *scene, sfRenderWindow *window)
{
    if (!scene || !window) {
        return;
    }
    sfRenderWindow_drawSprite(window, scene->background, NULL);
}

// FIXME: Dans ce cas, le retour de sf[...]_create() n'est pas vérifié par soucis de lisibilité. Merci de NE PAS FAIRE CA dans vos projets futur  
scene_t *create_pause_scene(void)
{
    scene_t *pause = malloc(sizeof(scene_t));

    if (!pause) {
        return NULL;
    }
    pause->id = PAUSE;
    pause->texture = sfTexture_createFromFile("assets/pause.jpg", NULL);
    pause->background = sfSprite_create(pause->texture);
    sfSprite_setPosition(pause->background, (sfVector2f){0, 0});
    pause->events = &pause_events;
    pause->update = &pause_update;
    pause->render = &pause_render;
    return pause;
}
