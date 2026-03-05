{% for system in system_list %}
  {% if loop.first %}
#ifdef {{system.series}}
  {% else %}
#elif {{system.series}}
  {% endif %}
  #include "{{system.fn}}"
{% endfor %}
#endif

