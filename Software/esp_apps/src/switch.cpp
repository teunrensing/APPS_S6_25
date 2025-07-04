#include "switch.hpp"
#include <Arduino.h>
#include <Wire.h>
#include <screens.h>
#include <vars.h>
#include <ui.h>
#include "helperfn.hpp"

icons_state buttons;

void init_icons()
{
  buttons.button1 = Display_Icon::SleepAlarm;
  buttons.button2 = Display_Icon::PillAlarm;
  buttons.button3 = Display_Icon::SpeechTrainer;
  buttons.button4 = Display_Icon::Blank;
  Wire.beginTransmission(0x08);
  Wire.write(buttons.button1);
  Wire.write(buttons.button2);
  Wire.write(buttons.button3);
  Wire.write(buttons.button4);
  Wire.endTransmission();
}
void send_icons()
{
  Wire.beginTransmission(0x08);
  Wire.write(buttons.button1);
  Wire.write(buttons.button2);
  Wire.write(buttons.button3);
  Wire.write(buttons.button4);
  Wire.endTransmission();
}
bool refresh = false;
void statemachine(int button)
{
  switch (button)
  {
  case 1:
    /// button 1
    switch (state)
    {
    case 0:
    {
      // Serial.println("0_1");
      switch (menu)
      {
      case 0:
      {
        // Serial.println("0_0_1");
        loadScreen(SCREEN_ID_SCREEN2);
        menu = 1;
        if (get_var_klok)
        {
          buttons.button1 = Display_Icon::Off;
        }
        else
        {
          buttons.button1 = Display_Icon::On;
        }
        buttons.button3 = Display_Icon::Edit;
        buttons.button2 = Display_Icon::Blank;
        buttons.button4 = Display_Icon::Blank;
      };
      break;
      case 1:
      {
        // Serial.println("1_0_1");
        if (wake_alarm)
        {
          wake_alarm = false;
          set_var_klok(false);
          buttons.button1 = Display_Icon::Off;
        }
        else
        {
          wake_alarm = true;
          set_var_klok(true);
          buttons.button1 = Display_Icon::On;
        }
      };
      break;
      case 2:
      {
        // Serial.println("2_0_1");
        //  timer -
        editTimeHourMinus();
      };
      break;
      case 3:
      {
        // Serial.println("3_0_1");
        editTimeMinutsMinus();
      };
      break;
      case 4:
      {
        // Serial.println("4_0_1");
        editTimeHourMinus();
      };
      break;
      }
    };
    break;
    case 1:
    {
      // Serial.println("1_1");
      switch (menu)
      {
      case 0:
      {
        // Serial.println("0_1_1");
        loadScreen(SCREEN_ID_SCREEN3);
        set_var_edit_time(get_var_alarm1());
        buttons.button1 = Display_Icon::Decrease;
        buttons.button3 = Display_Icon::Back;
        buttons.button2 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Next;
        menu = 1;
        alarm_state = 1;
      }
      break;
      case 1:
      {
        // Serial.println("1_1_1");
        switch (alarm_state)
        {
        case 1:
        {
          if (alarm1)
          {
            alarm1 = false;
            set_var_klok(false);
            buttons.button1 = Display_Icon::Off;
          }
          else
          {
            alarm1 = true;
            set_var_klok(true);
            buttons.button1 = Display_Icon::On;
          }
        }
        break;
        case 2:
        {
          if (alarm2)
          {
            alarm2 = false;
            set_var_klok(false);
            buttons.button1 = Display_Icon::Off;
          }
          else
          {
            alarm2 = true;
            set_var_klok(true);
            buttons.button1 = Display_Icon::On;
          }
        }
        break;
        case 3:
        {
          if (alarm3)
          {
            alarm3 = false;
            set_var_klok(false);
            buttons.button1 = Display_Icon::Off;
          }
          else
          {
            alarm3 = true;
            set_var_klok(true);
            buttons.button1 = Display_Icon::On;
          }
        }
        break;
        case 4:
        {
          if (alarm4)
          {
            alarm4 = false;
            set_var_klok(false);
            buttons.button1 = Display_Icon::Off;
          }
          else
          {
            alarm4 = true;
            set_var_klok(true);
            buttons.button1 = Display_Icon::On;
          }
        }
        break;
        }
      }
      break;
      case 2:
      {
        // Serial.println("2_1_1");
        editTimeHourMinus();
      }
      break;
      case 3:
      {
        // Serial.println("3_1_1");
        editTimeMinutsMinus();
      }
      break;
      }
    };
    break;
    }
    break;
  case 2:
    /// button 2
    switch (state)
    {
    case 0:
    {
      buttons.button1 = Display_Icon::Digit1;
      buttons.button3 = Display_Icon::Digit2;
      buttons.button2 = Display_Icon::Digit3;
      buttons.button4 = Display_Icon::Digit4;
      loadScreen(SCREEN_ID_SCREEN1);
      state = 1;
      set_var_edit_box2(true);
      set_var_edit_box1(false);
      set_var_edit_text_bool(true);
    };
    break;
    case 1:
    {
      // Serial.println("1_2");

      // Serial.println("0_1_2");
      loadScreen(SCREEN_ID_SCREEN3);
      set_var_edit_time(get_var_alarm2());
      buttons.button1 = Display_Icon::Decrease;
      buttons.button3 = Display_Icon::Blank;
      buttons.button2 = Display_Icon::Increase;
      buttons.button4 = Display_Icon::Next;
      alarm_state = 2;
      menu = 1;
    };
    break;
    case 2:
    {
      // Serial.println("2_2");
      if (get_var_volume() > 0)
      {
        int volume = get_var_volume();
        volume = volume - 10;
        set_var_volume(volume);
      }
    };
    }
    break;

  case 3:
    /// button 3
    switch (state)
    {
    case 0:
    {
      // Serial.println("0_3");
      switch (menu)
      {
      case 0:
      {
        // Serial.println("0_0_3");
        loadScreen(SCREEN_ID_SCREEN4);
        state = 2;
      };
      break;
      case 1:
      {
        // Serial.println("1_0_3");
        //  buttons.button1 = Display_Icon::Digit1;
        //   buttons.button2 = Display_Icon::Digit2;
        //   buttons.button3 = Display_Icon::Digit3;
        //   buttons.button4 = Display_Icon::Digit4;

        buttons.button1 = Display_Icon::Decrease;
        buttons.button2 = Display_Icon::Blank;
        buttons.button3 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Next;
        set_var_edit_text("slaap");
        loadScreen(SCREEN_ID_SCREEN_EDIT);
        set_var_edit_box2(true);
        set_var_edit_time(get_var_slaap());
        menu = 2;
      };
      break;
      case 2:
      {
        // Serial.println("2_0_3");
        //  timer +
        editTimeHourAdd();
      };
      break;
      case 3:
      {
        // Serial.println("3_0_3");
        editTimeMinutsAdd();
      };
      break;
      case 4:
      {
        // Serial.println("4_0_3");
        editTimeHourAdd();
      };
      break;
      case 5:
      {
        // Serial.println("5_0_3");
        editTimeMinutsAdd();
      };
      break;
      }
    };
    break;
    case 1:
    {
      // Serial.println("1_3");
      switch (menu)
      {
      case 0:
      {
        // Serial.println("0_1_3");
        loadScreen(SCREEN_ID_SCREEN3);
        set_var_edit_time(get_var_alarm3());
        buttons.button1 = Display_Icon::Decrease;
        buttons.button2 = Display_Icon::Back;
        buttons.button3 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Next;
        alarm_state = 3;
        menu = 1;
      }
      break;
      case 1:
      {
        // Serial.println("1_1_3");
        loadScreen(SCREEN_ID_SCREEN_EDIT);
        buttons.button1 = Display_Icon::Decrease;
        buttons.button2 = Display_Icon::Blank;
        buttons.button3 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Next;
        set_var_edit_box2(true);
        menu = 2;
      }
      break;
      case 2:
      {
        // Serial.println("2_1_3");
        editTimeHourAdd();
      }
      break;
      case 3:
      {
        // Serial.println("3_1_3");
        editTimeMinutsAdd();
      }
      break;
      }
    };
    break;
    case 2:
    {
      switch (menu)
      {
      case 0:
        loadScreen(SCREEN_ID_SCREEN4);
        buttons.button1 = Display_Icon::Blank;
        buttons.button2 = Display_Icon::Start;
        buttons.button3 = Display_Icon::VolumeDown;
        buttons.button4 = Display_Icon::VolumeUp;
        menu = 1;
        break;
      case 1:
        loadScreen(SCREEN_ID_SCREEN_SPRAAK);
        menu = 0;
        break;
      }
      // Serial.println("2_3");
    };
    break;
    }
    break;
  case 4:
    /// button4
    switch (state)
    {
    case 0:
    {
      // Serial.println("0_4");
      switch (menu)
      {
      case 0:
      {
        trainer = true;
      };
      break;
      case 2:
      {
        // Serial.println("2_0_4");
        menu = 3;
        buttons.button1 = Display_Icon::Decrease;
        buttons.button2 = Display_Icon::Back;
        buttons.button3 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Next;
        set_var_edit_box2(false);
        set_var_edit_box1(true);
      };
      break;
      case 3:
      {
        // Serial.println("3_0_4");
        set_var_slaap(get_var_edit_time());
        set_var_edit_time(get_var_wakker());
        set_var_edit_box2(true);
        set_var_edit_box1(false);
        set_var_edit_text("wakker");
        buttons.button1 = Display_Icon::Decrease;
        buttons.button2 = Display_Icon::Blank;
        buttons.button3 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Confirm;
        menu = 4;
      };
      break;
      case 4:
      {
        // Serial.println("4_0_4");
        buttons.button1 = Display_Icon::Decrease;
        buttons.button2 = Display_Icon::Back;
        buttons.button3 = Display_Icon::Increase;
        buttons.button4 = Display_Icon::Next;
        set_var_edit_box2(false);
        set_var_edit_box1(true);
        menu = 5;
      };
      break;
      case 5:
      {
        // Serial.println("5_0_4");

        buttons.button1 = Display_Icon::On;
        buttons.button3 = Display_Icon::Edit;
        buttons.button2 = Display_Icon::Blank;
        buttons.button4 = Display_Icon::Blank;
        set_var_wakker(get_var_edit_time());
        loadScreen(SCREEN_ID_SCREEN2);

        menu = 1;
      };
      break;
      }
    };
    break;
    case 1:
    {
      // Serial.println("1_4");
      switch (menu)
      {
      case 0:
      {
        // Serial.println("0_1_4");
        loadScreen(SCREEN_ID_SCREEN3);
        set_var_edit_time(get_var_alarm4());
       buttons.button1 = Display_Icon::On;
        buttons.button3 = Display_Icon::Edit;
        buttons.button2 = Display_Icon::Blank;
        buttons.button4 = Display_Icon::Blank;
        alarm_state = 4;
        menu = 1;
      }
      break;
      case 2:
      {
        set_var_edit_box2(false);
        set_var_edit_box1(true);
        menu = 3;
        // Serial.println("2_1_4");
      }
      break;
      case 3:
      {
        // Serial.println("3_1_4");
        menu = 0;
        state = 0;
        switch (alarm_state)
        {
        case 1:
          set_var_alarm1(get_var_edit_time());
          break;
        case 2:
          set_var_alarm2(get_var_edit_time());
          break;
        case 3:
          set_var_alarm3(get_var_edit_time());
          break;
        case 4:
          set_var_alarm4(get_var_edit_time());
          break;

        default:
          break;
        }
      }
        loadScreen(SCREEN_ID_SCREEN1);
        buttons.button1 = Display_Icon::SleepAlarm;
        buttons.button2 = Display_Icon::PillAlarm;
        buttons.button3 = Display_Icon::SpeechTrainer;
        buttons.button4 = Display_Icon::Blank;
        break;
      }
    };
    break;
    case 2:
    {
      if (get_var_volume() < 100)
      {
        int volume = get_var_volume();
        volume = volume + 10;
        set_var_volume(volume);
      }
      // Serial.println("2_4");
    };
    break;
    }
    break;

  default:

    break;
  }
}

unsigned long hhmm_to_millis(const char *time_str)
{
  int hh = 0, mm = 0;
  if (sscanf(time_str, "%d:%d", &hh, &mm) == 2)
  {
    hh = hh % 24;
    mm = mm % 60;
    return (hh * 3600UL + mm * 60UL) * 1000UL;
  }
  return 0;
}
