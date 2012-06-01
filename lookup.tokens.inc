<?php

/**
 * @file
 * Tokens integration for the Lookup details module.
 */

/**
 * Implements hook_token_info_alter().
 */
function lookup_token_info_alter(&$info) {
  $info['tokens']['user']['lookup-name'] = array(
    'name' => t('Lookup name'),
    'description' => t('The user\'s name as set in Lookup.'),
  );
}

/**
 * Implements hook_tokens().
 */
function lookup_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'user' && !empty($data['user'])) {
    $account = $data['user'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'lookup-name':
          if (isset($account->lookup)) {
            $replacements[$original] = $sanitize ? check_plain($account->lookup['name']) : $account->lookup['name'];
          }
          break;
      }
    }
  }

  return $replacements;
}