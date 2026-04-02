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

static void game_events(scene_t *scene, sfRenderWindow *window, scene_id_t *current_scene)
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
            if (evt.key.code == sfKeyEscape) {
                *current_scene = PAUSE;
            }
        }
    }
}

static void game_update(scene_t *scene)
{
    if (!scene) {
        return;
    }
}

static void game_render(scene_t *scene, sfRenderWindow *window)
{
    if (!scene || !window) {
        return;
    }
    sfRenderWindow_drawSprite(window, scene->background, NULL);
}

// FIXME: Dans ce cas, le retour de sf[...]_create() n'est pas vérifié par soucis de lisibilité. Merci de NE PAS FAIRE CA dans vos projets futur  
scene_t *create_game_scene(void)
{
    scene_t *game = malloc(sizeof(scene_t));

    if (!game) {
        return NULL;
    }
    game->id = GAME;
    game->texture = sfTexture_createFromFile("assets/game.png", NULL);
    game->background = sfSprite_create();
    sfSprite_setTexture(game->background, game->texture, sfFalse);
    sfSprite_setPosition(game->background, (sfVector2f){0, 0});
    game->events = &game_events;
    game->update = &game_update;
    game->render = &game_render;
    return game;
}
