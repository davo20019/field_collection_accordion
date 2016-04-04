(function($) {
  Drupal.behaviors.accordion_entityreference = {
    attach: function (context, settings) {

      if ($.type(settings.field_collection_accordion) !== 'undefined') {
        var accordion = settings.field_collection_accordion;
        $.each(accordion, function(index, element) {
          //Initialization
          var id = element.accordion_id;
          var header  = element.accordion_header;
          var content = element.accordion_content;
          var view = element.view;
          var htmlId = element.htmlId;
          var tabActive = false;
          var panel = false;
          var hash = false;

          // //Define tab active
          if (htmlId != undefined) {
            hash = $(htmlId).parents(content).attr('aria-labelledby');
          }

          //Define accordion
          $("#"+id).accordion({
            collapsible: true,
            active: view,
            header: header,
            heightStyle: "content",
            navigation: true
          });

          //if exist defined header
          if (hash != false && hash != undefined) {

            //Open the accordion for hash
            $('#'+hash).trigger( "click" );
          }

        });
      }
    }
 }
}(jQuery));
