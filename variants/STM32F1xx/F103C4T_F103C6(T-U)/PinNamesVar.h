/* Alternate pin name */
PA_0_ALT1  = PA_0  | ALT1,
PA_1_ALT1  = PA_1  | ALT1,
PA_2_ALT1  = PA_2  | ALT1,
PA_3_ALT1  = PA_3  | ALT1,
PA_4_ALT1  = PA_4  | ALT1,
PA_5_ALT1  = PA_5  | ALT1,
PA_6_ALT1  = PA_6  | ALT1,
PA_7_ALT1  = PA_7  | ALT1,
PA_8_ALT1  = PA_8  | ALT1,
PA_9_ALT1  = PA_9  | ALT1,
PA_10_ALT1 = PA_10 | ALT1,
PA_11_ALT1 = PA_11 | ALT1,
PA_15_ALT1 = PA_15 | ALT1,
PB_0_ALT1  = PB_0  | ALT1,
PB_0_ALT2  = PB_0  | ALT2,
PB_1_ALT1  = PB_1  | ALT1,
PB_1_ALT2  = PB_1  | ALT2,
PB_3_ALT1  = PB_3  | ALT1,
PB_10_ALT1 = PB_10 | ALT1,
PB_11_ALT1 = PB_11 | ALT1,

/* SYS_WKUP */
#ifdef PWR_WAKEUP_PIN1
  SYS_WKUP1 = PA_0,
#endif

/* USB */
#ifdef USBCON
  USB_DM = PA_11,
  USB_DP = PA_12,
#endif
