# BatteryChecker
## why?
**why not? more precisely boredom.** 
this is the most overengineered way to get notifications when your laptop is about to die, when using qubes with i3 window manager!
you shouldn't really use this theres probably a better implementations of this exact functions somewhere else but it is marginally more secure in the scenario where a malicious battery firmware that could cause arbitrary code execution but if you're optimizing for that i dont think you'd trust C or a compiler?
## how to use 
if you want to use its very simple
**compile**
```bash 
gcc BatteryChecker.c -o check $(pkg-config --cflags --libs libnotify) 
```
use qvm-copy to send to desired vm (can be any vm really they all take notifications the same)
```bash
qvm-copy check
```
**service**
now copy service.sh to dom0 and run it 
```bash
qvm-run -p target-vm cat /path/in/target/vm.sh > service.sh
```
now just run it make sure service.sh points to the desired vm, and run it!
