/* Remap pin name */
PA_11_R   = PA_11 | PREMAP,
PA_12_R   = PA_12 | PREMAP,

/* Alternate pin name */
PA_6_ALT1 = PA_6 | ALT1,
PA_7_ALT1 = PA_7 | ALT1,
PA_7_ALT2 = PA_7 | ALT2,
PA_7_ALT3 = PA_7 | ALT3,
PB_0_ALT1 = PB_0 | ALT1,
PB_1_ALT1 = PB_1 | ALT1,
PB_1_ALT2 = PB_1 | ALT2,

/* SYS_WKUP */
#ifdef PWR_WAKEUP_PIN1
  SYS_WKUP1 = PA_0,
#endif
#ifdef PWR_WAKEUP_PIN2
  SYS_WKUP2 = NC,
#endif
#ifdef PWR_WAKEUP_PIN3
  SYS_WKUP3 = NC,
#endif
#ifdef PWR_WAKEUP_PIN4
  SYS_WKUP4 = PA_2,
#endif
#ifdef PWR_WAKEUP_PIN5
  SYS_WKUP5 = NC,
#endif
#ifdef PWR_WAKEUP_PIN6
  SYS_WKUP6 = PB_5,
#endif

/* USB */
#ifdef USBCON
  USB_DM  = PA_11_R,
  USB_DP  = PA_12_R,
  #ifdef USB_NOE_PA_4
    USB_NOE = PA_4,
  #endif
  #ifdef USB_NOE_PA_13
    USB_NOE = PA_13,
  #endif
  #ifdef USB_NOE_PA_15
    USB_NOE = PA_15,
  #endif
#endif
