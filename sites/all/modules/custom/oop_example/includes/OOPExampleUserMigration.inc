<?php

/**
 * @file
 * Migration for User data.
 */

class OOPExampleUserMigration extends OOPExampleMigration {

  public function __construct ($args) {
    parent::__construct($args);

    // Avoid known line ending issue: "Invalid data value" at drupal.org/node/1152158#InvalidDataValue
    ini_set('auto_detect_line_endings', TRUE);

    $this->description = t('Import Users from CSV file.');

    $csv = drupal_get_path('module', 'oop_example') . '/data/staff.csv';

    $columns = array(
      0 => array('ID', t('ID')),
      1 => array('Name', t('Name')),
      2 => array('Email', t('Email')),
    );

    $this->source = new MigrateSourceCSV($csv, $columns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'ID' => array(
          'type' => 'varchar',
          'length' => 60,
          'not null' => true,
          'description' => 'User ID',
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    $this->addFieldMapping('mail', 'Email');

    $this->addUnmigratedSources(array(
      'Id',
      'Name',
    ));

    $this->addUnmigratedDestinations(array(
      'uid',
      'pass',
      'created',
      'access',
      'login',
      'roles',
      'role_names',
      'picture',
      'signature',
      'signature_format',
      'timezone',
      'language',
      'theme',
      'init',
      'data',
      'is_new',
      'path',
    ));
  }
}
