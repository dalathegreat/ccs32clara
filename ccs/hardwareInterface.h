/* Interface header for hardwareInterface.c */

/* Global Defines */
#define CAN_TIMEOUT 30 //multiples of 100ms

#define ACTUTEST_STATUS_IDLE 0
#define ACTUTEST_STATUS_LOCKING_TRIGGERED 1
#define ACTUTEST_STATUS_UNLOCKING_TRIGGERED 2

enum LockStt
{
   LOCK_UNKNOWN, LOCK_OPEN, LOCK_CLOSED, LOCK_OPENING, LOCK_CLOSING
};

/* Global Variables */


/* Global Functions */
#ifdef __cplusplus
extern "C" {
#endif

#define IOCONTROL_LOCK_RETURN_CONTROL_TO_ECU 0
#define IOCONTROL_LOCK_CLOSE 1
#define IOCONTROL_LOCK_OPEN 2

#define BOTH_CONTACTORS 3

#define RGB_OFF 0
#define RGB_RED 1
#define RGB_GREEN 2
#define RGB_BLUE 4
#define RGB_CYAN 6
#define RGB_WHITE 7

extern void hardwareInteface_setHBridge(uint16_t out1duty_4k, uint16_t out2duty_4k);
extern void hwIf_connectorLockActuatorTest(uint8_t kindOfControl);
extern void hwIf_handleLockRequests(void);
extern void hwIf_handleInletVoltage(void);
extern void hardwareInterface_setStateB(void);
extern void hardwareInterface_setStateC(void);
extern void hardwareInterface_setPowerRelayOff(void);
extern void hardwareInterface_setPowerRelaysOn(uint8_t contactorSelection);
extern void hardwareInterface_setRGB(uint8_t rgb);
extern void hardwareInterface_triggerConnectorLocking(void);
extern void hardwareInterface_triggerConnectorUnlocking(void);
extern uint8_t hardwareInterface_isConnectorLocked(void);
extern uint8_t hardwareInterface_getPowerRelayConfirmation(void);
extern bool hardwareInterface_stopChargeRequested();
extern uint8_t hardwareInterface_getIsAccuFull(void);
extern uint8_t hardwareInterface_getSoc(void);
extern void hardwareInterface_simulateCharging(void);
extern void hardwareInterface_resetSimulation(void);
extern void hardwareInterface_simulatePreCharge(void);
extern int16_t hardwareInterface_getAccuVoltage(void);
extern int16_t hardwareInterface_getChargingTargetVoltage(void);
extern int16_t hardwareInterface_getChargingTargetCurrent(void);
extern void hardwareInterface_WakeupOtherPeripherals();
extern void hardwareInterface_LogTheCpPpPhysicalData();
extern uint8_t hardwareInterface_isPpMeasurementInvalid(void);
extern void hardwareInterface_cyclic(void);
extern void hardwareInterface_init(void);

/* shared variables */
extern uint8_t hwIf_isInletVoltageError;

#ifdef __cplusplus
}
#endif
