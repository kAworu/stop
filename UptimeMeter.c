/*
htop
(C) 2004-2006 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "UptimeMeter.h"
#include "Meter.h"
#include "Sysctl.h"

#include "ProcessList.h"

#include "CRT.h"

#include "debug.h"

int UptimeMeter_attributes[] = {
   UPTIME
};

static void UptimeMeter_setValues(Meter* this, char* buffer, int len) {
   static struct timeval *boottime = NULL;
   struct timeval now, diff;

   if (boottime == NULL) {
       size_t size;
       boottime = Sysctl.get("kern.boottime", &size);
       if (size != sizeof(struct timeval))
           assert(("wrong size for kern.boottime", 0));
   }

   if (gettimeofday(&now, NULL) != 0)
       assert(("gettimeofday failed", 0));
   timersub(&now, boottime, &diff);

   double uptime = (double)(diff.tv_sec + diff.tv_usec * 1e-6);
   int totalseconds = (int) ceil(uptime);
   int seconds = totalseconds % 60;
   int minutes = (totalseconds/60) % 60;
   int hours = (totalseconds/3600) % 24;
   int days = (totalseconds/86400);
   this->values[0] = days;
   if (days > this->total) {
      this->total = days;
   }
   char daysbuf[15];
   if (days > 100) {
      sprintf(daysbuf, "%d days(!), ", days);
   } else if (days > 1) {
      sprintf(daysbuf, "%d days, ", days);
   } else if (days == 1) {
      sprintf(daysbuf, "1 day, ");
   } else {
      daysbuf[0] = '\0';
   }
   snprintf(buffer, len, "%s%02d:%02d:%02d", daysbuf, hours, minutes, seconds);
}

MeterType UptimeMeter = {
   .setValues = UptimeMeter_setValues, 
   .display = NULL,
   .mode = TEXT_METERMODE,
   .items = 1,
   .total = 100.0,
   .attributes = UptimeMeter_attributes,
   .name = "Uptime",
   .uiName = "Uptime",
   .caption = "Uptime: "
};
