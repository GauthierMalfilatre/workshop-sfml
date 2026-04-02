/*
** EPITECH PROJECT, 2026
** WORKSHOP
** File description:
** Scene structures for SFML
*/
#ifndef SCENE_H
    #define SCENE_H
    #include <SFML/Graphics/Types.h>
#include <stddef.h>
    #include "SFML/Graphics/RenderWindow.h"

typedef enum scene_id_e {

    MENU,
    GAME,
    PAUSE

} scene_id_t;

typedef struct scene_s {

    scene_id_t id;

    sfTexture *texture;
    sfSprite *background;

    void (*events)(struct scene_s *, sfRenderWindow *, scene_id_t *);
    void (*update)(struct scene_s *);
    void (*render)(struct scene_s *, sfRenderWindow *);

} scene_t;


scene_t *create_menu_scene(void);
scene_t *create_game_scene(void);
scene_t *create_pause_scene(void);

#endif /* SCENE_H */
