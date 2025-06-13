

// Statemachine 
// void statemachine_button1();
// void statemachine_button2();
// void statemachine_button3();
// void statemachine_button4();
static int menu = 0;
static int alarm_state = 0;
static int state = 0;
static int button_state = 0;
static bool data_requested = false;

void statemachine(int id);
