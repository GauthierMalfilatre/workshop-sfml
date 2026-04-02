/*
** EPITECH PROJECT, 2026
** WORKSHOP
** File description:
** Main int.c
*/
#include "scene.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowBase.h>

int main(void)
{
    scene_t *scenes[3] = {};
    scene_id_t current_scene = MENU;
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "FEUR", sfResize | sfClose, 0);

    scenes[MENU] = create_menu_scene();
    scenes[GAME] = create_game_scene();
    scenes[PAUSE] = create_pause_scene();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        scenes[current_scene]->events(scenes[current_scene], window, &current_scene);
        scenes[current_scene]->update(scenes[current_scene]);
        scenes[current_scene]->render(scenes[current_scene], window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
