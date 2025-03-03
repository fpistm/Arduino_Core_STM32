/* Alternate pin name */
PA_2_ALT1  = PA_2  | ALT1,
PA_3_ALT1  = PA_3  | ALT1,
PA_6_ALT1  = PA_6  | ALT1,
PA_7_ALT1  = PA_7  | ALT1,
PA_14_ALT1 = PA_14 | ALT1,
PB_4_ALT1  = PB_4  | ALT1,
PB_5_ALT1  = PB_5  | ALT1,
PC_6_ALT1  = PC_6  | ALT1,
PC_7_ALT1  = PC_7  | ALT1,
PC_10_ALT1 = PC_10 | ALT1,
PC_11_ALT1 = PC_11 | ALT1,
PE_3_ALT1  = PE_3  | ALT1,
PE_4_ALT1  = PE_4  | ALT1,
PE_5_ALT1  = PE_5  | ALT1,
PE_6_ALT1  = PE_6  | ALT1,

/* SYS_WKUP */
#ifdef PWR_WAKEUP_PIN1
  SYS_WKUP1 = PA_0,
#endif
#ifdef PWR_WAKEUP_PIN2
  SYS_WKUP2 = PC_13,
#endif
#ifdef PWR_WAKEUP_PIN3
  SYS_WKUP3 = PE_6,
#endif

/* USB */
#ifdef USBCON
  USB_DM  = PA_11,
  USB_DP  = PA_12,
  #ifdef USB_NOE_PA_13
    USB_NOE = PA_13,
  #endif
  #ifdef USB_NOE_PC_9
    USB_NOE = PC_9,
  #endif
#endif
