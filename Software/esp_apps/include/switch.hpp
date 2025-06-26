
#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "display_icons.hpp"

static int menu = 0;
static int alarm_state = 0;
static int state = 0;
static int button_state = 0;
static bool data_requested = false;

//icons_state buttons;
void init_icons();
void send_icons();
void statemachine(int button);

#endif
