# Workshop SFML

---

## How to launch

In order to use this workshop exemple, you need to compile and run the programm.
To do so:
```shell
cd sample/
make
./workshop
```

---

Exemples:

Gameloop du wolf3D
```c
static int wolf(bst_context_t *context)
{
    while (sfRenderWindow_isOpen(context->view->window)) {
        while (sfRenderWindow_pollEvent(context->view->window, &context->evt))
            scenes[context->current_scene].event(context);
        scenes[context->current_scene].update(context);
        scenes[context->current_scene].draw(context);
        sfRenderWindow_display(context->view->window);
    }
    return OK;
}
```

<br>

Gameloop du my_world
```c
int main(int argc, char *const *argv)
{
    data_t *data = create_data();

    while (sfRenderWindow_isOpen(data->window)) {
        if (data->scenes[data->actual_scene]->events) {
            data->scenes[data->actual_scene]->events(data);
        }
        sfRenderWindow_clear(data->window, sfBlack);
        if (data->scenes[data->actual_scene]->render) {
            data->scenes[data->actual_scene]->render(data);
        }
        sfRenderWindow_setView(data->window, data->view);
        sfRenderWindow_display(data->window);
    }
    destroy_data(data);
    return 0;
}
```
<br>

Gameloop du my_radar
```c
int main(int argc, char *const *argv)
{
    radar_t *radar = create_radar(argv[1]);

    while (sfRenderWindow_isOpen(radar->window)) {
        sfRenderWindow_clear(radar->window, sfBlack);
        radar->scenes[radar->scene_in]->events(radar);
        radar->scenes[radar->scene_in]->timer(radar);
        radar->scenes[radar->scene_in]->mover(radar);
        radar->scenes[radar->scene_in]->render(radar);
        print_framerate();
        sfRenderWindow_display(radar->window);
    }
    destroy_radar(radar);
    return 0;
}
```

---

###### Gauthier Malfilatre, 2026
