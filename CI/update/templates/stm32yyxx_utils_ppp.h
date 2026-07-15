#ifndef _STM32YYXX_UTILS_{{feat.upper()}}_H_
#define _STM32YYXX_UTILS_{{feat.upper()}}_H_
/* LL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#ifdef __cplusplus
  #pragma GCC diagnostic ignored "-Wregister"
#endif

{% for series, nx, is_series_in_fn, utils in serieslist %}
  {% if loop.first %}
#ifdef STM32{{series.upper()}}{{nx}}
  {% else %}
#elif STM32{{series.upper()}}{{nx}}
  {% endif %}
  {% if is_series_in_fn %}
  #include "stm32{{series}}{{nx}}_{{'utils' if utils else 'util'}}_{{feat}}.h"
  {% else %}
  #include "stm32_{{'utils' if utils else 'util'}}_{{feat}}.h"
  {% endif %}
  {% if loop.last %}
#endif
  {% endif %}
{% endfor %}
#pragma GCC diagnostic pop
#endif /* _STM32YYXX_UTILS_{{feat.upper()}}_H_ */

