/*
** EPITECH PROJECT, 2026
** WORKSHOP
** File description:
** Main int.c
*/
#include "../scene.h"
#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>

static void menu_events(scene_t *scene, sfRenderWindow *window, scene_id_t *current_scene)
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
            }
        }
    }
}

static void menu_update(scene_t *scene)
{
    if (!scene) {
        return;
    }
}

static void menu_render(scene_t *scene, sfRenderWindow *window)
{
    if (!scene || !window) {
        return;
    }
    sfRenderWindow_drawSprite(window, scene->background, NULL);
}

// FIXME: Dans ce cas, le retour de sf[...]_create() n'est pas vérifié par soucis de lisibilité. Merci de NE PAS FAIRE CA dans vos projets futur  
scene_t *create_menu_scene(void)
{
    scene_t *menu = malloc(sizeof(scene_t));

    if (!menu) {
        return NULL;
    }
    menu->id = MENU;
    menu->texture = sfTexture_createFromFile("assets/menu.jpg", NULL);
    menu->background = sfSprite_create();
    sfSprite_setTexture(menu->background, menu->texture, sfFalse);
    sfSprite_setPosition(menu->background, (sfVector2f){0, 0});
    menu->events = &menu_events;
    menu->update = &menu_update;
    menu->render = &menu_render;
    return menu;
}
