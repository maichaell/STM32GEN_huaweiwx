/**
  ******************************************************************************
    @file    SimpleRTC_set.ino
    @author  huaweiwx@sina.com
    @date    2018/6/8
    @brief   Simple RTC set time example.
  ******************************************************************************
*/

#include <cmdline.h>
char cmdline[256];
int ptr = 0;

#include <Streaming.h>
#include <LED.h>

#include <STM32RTC.h>
STM32RTC& rtc = STM32RTC::getInstance(); /* Get the rtc object */


void setup()
{
  Serial.begin(115200);
  Led.Init();
  Led.flash(10, 320, 5);

  Serial.println();
  Serial.println("****************************************");
  Serial.println("*          RTC timer demo              *");
  Serial.println("*  Type help Display list of commands  *");
  Serial.println("****************************************");

  //select clock souce:  RTC_LSI_CLOCK/RTC_LSE_CLOCK/RTC_HSE_CLOCK/RTC_HSI_CLOCK, default RTC_LSI_CLOCK
  //default STM32RTC::RTC_LSI_CLOCK
  rtc.setClockSource(STM32RTC::RTC_LSE_CLOCK);

  rtc.begin(); // initialize RTC default 24H format

  //check bkreg and set the data/time
  if (rtc.getRegister(RTC_BKP_DR1) != 0x32F2) {
    setdata();
    settime();
    rtc.setRegister(RTC_BKP_DR1, 0x32F2);
  } else {
    //   settime()
#ifdef STM32F1
    setdata();
#endif
  }
  // you can use also
  //rtc.setTime(hours, minutes, seconds);
  //rtc.setDate(weekDay, day, month, year);
}

boolean stringComplete = false;  // whether the string is complete
void loop()
{
  //cmdline process
  int nStatus;
  if (stringComplete) {
    if (cmdline[0] > ' ') {
      nStatus = CmdLineProcess(cmdline);
      if (nStatus == CMDLINE_BAD_CMD)
        Serial.println(F("Bad cmd!"));
      else if (nStatus == CMDLINE_TOO_MANY_ARGS)
        Serial.println(F("Too many args!"));
      else if (nStatus != 0)
        Serial << "Cmd rtn err_code:" << nStatus;
    }
    ptr = 0;
    stringComplete = false;
  }

  showDataTime();
  //receiver uart input
#if defined(STM32GENERIC)
  serialEvent();
#endif
 delay(1000);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    cmdline[ptr++] = inChar;
    cmdline[ptr] = '\0';
    if ((inChar == '\n') || (inChar == '\r')) {
      stringComplete = true;
    }
  }
}

const char*  weekStr[7] = {
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
  "Sunday",
};

void showDataTime(void)
{
  Serial <<  rtc.getHours() << ":"  << rtc.getMinutes() << ":" << rtc.getSeconds() ;
  Serial << "  "<< weekStr[ rtc.getWeekDay() - 1] <<"  "<<  rtc.getDay() << "/" <<  rtc.getMonth()   << "/"<< rtc.getYear() << "\n";
}

/* Change these values to set the current initial time */
byte seconds = 0;
byte minutes = 0;
byte hours = 18;

/* Change these values to set the current initial date */
/* Menday  19th June 2018 */
byte weekDay = 2;
byte day = 19;
byte month = 5;
byte year = 18;

//  set the time
void settime(void) {
  rtc.setHours(hours);
  rtc.setMinutes(minutes);
  rtc.setSeconds(seconds);
}

// Set the date
void setdata(void) {
  rtc.setWeekDay(weekDay);
  rtc.setDay(day);
  rtc.setMonth(month);
  rtc.setYear(year);
}

/*setdt 19 12 8 12 08 58*/
int Cmd_setdt(int argc, char *argv[])
{
  switch (argc) {
    case 7:
      year = atoi(argv[1]);
      month = atoi(argv[2]);
      day = atoi(argv[3]);
      hours = atoi(argv[4]);
      minutes = atoi(argv[5]);
      seconds = atoi(argv[6]);
      break;
    case 6:
      month = atoi(argv[1]);
      day = atoi(argv[2]);
      hours = atoi(argv[3]);
      minutes = atoi(argv[4]);
      seconds = atoi(argv[5]);
      break;
    case 5:
      day = atoi(argv[1]);
      hours = atoi(argv[2]);
      minutes = atoi(argv[3]);
      seconds = atoi(argv[4]);
      break;
    case 4:
      hours = atoi(argv[1]);
      minutes = atoi(argv[2]);
      seconds = atoi(argv[3]);
      break;
    case 3:
      minutes = atoi(argv[1]);
      seconds = atoi(argv[2]);
      break;
    case 2:
      seconds = atoi(argv[1]);
      break;
    default:
      return 0;
  }
  rtc.setYear(year);
  rtc.setMonth(month);
  rtc.setDay(day);
  rtc.setHours(hours);
  rtc.setMinutes(minutes);
  rtc.setSeconds(seconds);

  return 0;
}

/*setwk  1~7*/
int Cmd_setwk(int argc, char *argv[])
{
  switch (argc) {
    case 2:
      weekDay = atoi(argv[1]);
      break;
    default:
      return 0;
  }
  
  rtc.setWeekDay(weekDay);
  return 0;
}


//*****************************************************************************
// This function implements the "help" command.  It prints a simple list of the
// available commands with a brief description.
//*****************************************************************************
int Cmd_help(int argc, char *argv[])
{
  tCmdLineEntry *pEntry;
  pEntry = &g_sCmdTable[0];
  Serial.println(F("\r\nAvailable commands:\r\n------------------\n"));
  while (pEntry->pcCmd)
  {
    Serial.print( pEntry->pcCmd);
    Serial.println(pEntry->pcHelp);
    pEntry++;
  }
  return (0);
}

tCmdLineEntry g_sCmdTable[] =
{
  { "help",      Cmd_help,      " : Display list of commands"} ,
  { "?",         Cmd_help,      "    : alias for help"} ,
  { "set",       Cmd_setdt,     "  : set  yy mm dd hh mm ss"} ,/* set 18 6 9 22 18 54 */ 
  { "wkset",     Cmd_setwk,     ": wkset wk"} ,                /* setwk 6 */  
  
  // { "alarm",      Cmd_alarm,    "  :  set alarmtime hms"},
  {  0, 0, 0 }
};
