<?php
/**
* @file
* Default output for a Accordion object.
*/

?>
<?php if ($settings['label']): ?>
  <div class="field-label"<?php print $title_attributes; ?>><?php print $settings['label'] ?>:&nbsp;</div>
<?php endif; ?>
<div <?php print drupal_attributes($settings['attributes'])?>>
  <?php foreach ($items as $key => $item): ?>
    <?php print $item['item']; ?>
  <?php endforeach; ?>
</div>