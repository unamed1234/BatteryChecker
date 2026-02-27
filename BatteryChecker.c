#include <stdio.h>
#include <libnotify/notify.h>

int main(void) {
        //FILE *f = fopen("/sys/class/power_supply/BAT0/capacity", "r");
	int nums[3];
	int count=0;
	count=fscanf(stdin, "%d%d%d",&nums[0],&nums[1],&nums[2]);
	if(count<1) {
		fprintf(stderr,"ERR: no integers provided \n");
		return 1;
	}
//	printf("Read %d integer:", nums, "\n");
	for(int i=0; i<count;i++) {
		notify_init("low battery Monitor");
		if (nums[i]<15) {
			printf("less than 15%%\n");
			NotifyNotification* n=notify_notification_new("Battery Low", "less than 15%%", NULL);
			notify_notification_set_urgency(n,NOTIFY_URGENCY_CRITICAL);
			notify_notification_show(n,NULL);
			g_object_unref(G_OBJECT(n));
			break;
			}
		}
	notify_uninit();
	return 0;
			}

