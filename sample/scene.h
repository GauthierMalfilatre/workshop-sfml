/*
** EPITECH PROJECT, 2026
** WORKSHOP
** File description:
** Scene structures for SFML
*/
#ifndef SCENE_H
    #define SCENE_H
    #include <SFML/Graphics/Types.h>
    #include "SFML/Graphics/RenderWindow.h"
    #include <stddef.h>

/**
 * @brief Enum pour les différentes scenes
 */
typedef enum scene_id_e {

    MENU,  //!< ID de la scene menu
    GAME,  //!< ID de la scene game
    PAUSE  //!< ID de la scene pause

} scene_id_t;

/**
 * @brief Structure générique de scene
 */
typedef struct scene_s {

    scene_id_t id;                                                     //!< ID de la scene

    sfTexture *texture;                                                //!< Texture du background de la scene
    sfSprite *background;                                              //!< Sprite du background de la scene

    void (*events)(struct scene_s *, sfRenderWindow *, scene_id_t *);  //!< Pointeur sur fonction de la partie "events" de la scene
    void (*update)(struct scene_s *);                                  //!< Pointeur sur fonction de la partie "update" de la scene
    void (*render)(struct scene_s *, sfRenderWindow *);                //!< Pointeur sur fonction de la partie "render" de la scene

} scene_t;

scene_t *create_menu_scene(void);
scene_t *create_game_scene(void);
scene_t *create_pause_scene(void);

void destroy_scene(scene_t *scene);

#endif /* SCENE_H */
