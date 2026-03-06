use std::io;
use notify_rust::Notification;
use notify_rust::Urgency;

fn main() {
    let mut input: String = Default::default();
    io::stdin().read_line(&mut input).expect("err no info sent");
    if input < 15.to_string() {
        Notification::new().summary("bat_checker").body("your battery is below 15%!").urgency(Urgency::Critical).show().unwrap();
    }
}
