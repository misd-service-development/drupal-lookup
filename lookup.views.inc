<?php

/**
 * @file
 * Views integration for the Lookup details module.
 */

/**
 * Implements hook_views_data().
 */
function lookup_views_data() {
  $data['users_lookup_detail']['table']['group']  = t('Lookup');
  $data['users_lookup_detail']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['users_lookup_detail']['name'] = array(
    'title' => t('Lookup name'),
    'help' => t('The user\'s name as set in Lookup.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'title' => t('Name'),
      'help' => t('The user\'s name as set in Lookup.')
    ),
  );

  return $data;
}