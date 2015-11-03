<?php

/**
 * Implements hook_migrate_api()
 * @return array
 */
function oop_example_migrate_api () {
  return array(
    'api' => 2,
    'groups' => array(
      'oop_workshop' => array(
        'title' => t('OOP Workshop'),
      ),
    ),
    'migrations' => array(
      'OOPExampleUser' => array(
        'class_name' => 'OOPExampleUserMigration',
        'group_name' => 'oop_workshop',
      ),
      'OOPExampleArticle' => array(
        'class_name' => 'OOPExampleArticleMigration',
        'group_name' => 'oop_workshop',
      ),
    ),
  );

}
