<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_drush_command().
 */
function islandora_nested_collections_drush_command() {

  $items['create-home-page'] = array(
    'description' => 'Create the home page on which the collections will be displayed.',
    'aliases' => array('chp'),
  );

  return $items;
}

/**
 * Callback for the create_home_page command
 */
function drush_islandora_nested_collections_create_home_page() {
  create_home_page();
}

function create_home_page() {
  $node = new stdClass();
  $node->nid = NULL;
  $node->type = "page";
  node_object_prepare($node);
  $node->title = "";
  $node->uid = 1;
  $node->created = strtotime("now");
  $node->changed = strtotime("now");
  $node->sticky= 0;
  $node->language = LANGUAGE_NONE;
  $node->validated = TRUE;
  $node->body[$node->language][0]["value"]   = "";
  $node->body[$node->language][0]["summary"] = text_summary("");
  $node->body[$node->language][0]["format"]  = "filtered_html";
  $node->path = array("alias" => "home", "pathauto" => FALSE);

  node_save($node);
  variable_set('site_frontpage', "home");
  drupal_set_message(t('Created home page with node id ' . $node->nid) );
}