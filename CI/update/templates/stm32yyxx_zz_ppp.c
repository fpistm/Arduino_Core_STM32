/* {{type.upper()}} raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

{% for series, legacy, nx in serieslist %}
  {% if loop.first %}
#ifdef STM32{{series.upper()}}{{nx}}
  {% else %}
#elif STM32{{series.upper()}}{{nx}}
  {% endif %}
  {% if type == periph %}
  #include "stm32{{series}}{{nx}}_{{type}}.c"
  {% else %}
    {% if legacy %}
  #include "Legacy/stm32{{series}}{{nx}}_{{type}}_{{periph}}.c"
    {% endif %}
  #include "stm32{{series}}{{nx}}_{{type}}_{{periph}}.c"
  {% endif %}
  {% if loop.last %}
#endif
  {% endif %}
{% endfor %}
#pragma GCC diagnostic pop

