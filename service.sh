while true; do
	#in this case were using a appvm to actually parse the battery % and send the notification were using sys-net since 99% of the time its always running so it'll work
	cat /sys/class/power_supply/BAT0/capacity | qrexec-client -tTEd sys-net user:'/rw/config/check'
done
