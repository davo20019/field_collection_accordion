<?php
/**
 *
 * @file
 * Theming functions for the accordion_entityreference module.
 *
 */

/**
 * Template process handler for 'accordion_entityreference'.
 */
function template_process_field_collection_accordion(&$vars) {
  $settings =& $vars['settings'];

  $attributes       = array();
  $accordion_id     = &drupal_static('accordion_id', 0);
  $attributes['id'] = 'accordion-' . ++$accordion_id;
  $attributes['class'] = isset($settings['field_formatter_class']) ? $settings['field_formatter_class'] : '';

  $settings['attributes'] = $attributes;

  field_collection_accordion_js_settings($settings['attributes']['id'], $settings['header'], $settings['content'], $settings['view']);

  $vars['accordion'] += array(
    '#theme' => 'field_collection_accordion_field',
    '#items' => array(),
    '#settings' => $settings,
  );
  foreach ($vars['entities'] as $key => $delta) {
    $vars['accordion']['#items'][$key] = array(
      'item' => $delta,
    );
  }
}

/**
 * Default theme implementation for 'accordion_entityreference'.
 */
function theme_field_collection_accordion($vars) {
  $output = '';
  $output .= drupal_render($vars['accordion']);
  return $output;
}


