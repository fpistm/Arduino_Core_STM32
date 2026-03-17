/* No alternate */

/* SYS_WKUP */
#ifdef PWR_WAKEUP_PIN1
  SYS_WKUP1 = NC,
#endif
#ifdef PWR_WAKEUP_PIN2
  SYS_WKUP2 = NC,
#endif
#ifdef PWR_WAKEUP_PIN3
  SYS_WKUP3 = NC,
#endif
#ifdef PWR_WAKEUP_PIN4
  SYS_WKUP4 = NC,
#endif
#ifdef PWR_WAKEUP_PIN5
  SYS_WKUP5 = NC,
#endif
#ifdef PWR_WAKEUP_PIN6
  SYS_WKUP6 = PA_5,
#endif
#ifdef PWR_WAKEUP_PIN6
  SYS_WKUP6_1 = PA_12,
#endif
#ifdef PWR_WAKEUP_PIN7
  SYS_WKUP7 = PA_6,
#endif
#ifdef PWR_WAKEUP_PIN8
  SYS_WKUP8 = PB_9,
#endif

/* USB */
#ifdef USBCON
  USB_DM  = PB_9,
  USB_DP  = PB_8,
  USB_NOE = PA_13,
  USB_SOF = PA_8,
#endif
