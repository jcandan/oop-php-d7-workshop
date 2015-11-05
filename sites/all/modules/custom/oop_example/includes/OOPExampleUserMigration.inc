<?php

/**
 * @file
 * Migration for User data.
 */

class OOPExampleUserMigration extends OOPExampleMigration {

  public function __construct ($args) {
    parent::__construct($args);

    $this->description = t('Import Users from CSV file.');

  }
}