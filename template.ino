#include "ros_controller.hpp"

/*
  Variabili globali a disposizione:

  In lettura:
  motor_ctrl.dx // motore destro
  motor_ctrl.sx // motore sinistro

  Comandi di velocità dei motori.

  Valori: [-100, 100]
  -100: velocità massima indietro
  100: velocità massima avanti
  0: fermo

  I loro valori si aggiornano autoamticamente,
  dovete solo accedere a questi dati!

  In lettura:
  servo_ctrl.servo1
  servo_ctrl.servo2
  ...
  servo_ctrl.servo6

  Comandi di posizione dei servomotori.

  valoro ammessi: [0, 181+]
  da 0 a 180: muovi il servo dellangolo dato
  181+: non muovere il servo

  I loro valori si aggiornano autoamticamente,
  dovete solo accedere a questi dati!

  In scrittura:

  robot_status.battery_voltage
  robot_status.battery_current
  robot_status.current_sx
  robot_status.current_dx
  robot_status.distance
  robot_status.temperature
  robot_status.lux

  Questi valori devono essere settati da voi, esempio:

  robot_status.current_sx = analogRead(...)

  Il loro valore viene automaticamente inviato al raspberry
*/

void setup() {
  /*
    la prima funzione del setup e' ros_setup()
  */
  ros_setup();


}

void loop() {

  robot_status.battery_voltage = cnt++;
  robot_status.current_sx = analogRead(cspin[0]);
  robot_status.current_dx = analogRead(cspin[0]);

  /*
    Le ultime due istruzioni sono queste
  */

  ros_spin();
  delay(10);
}
