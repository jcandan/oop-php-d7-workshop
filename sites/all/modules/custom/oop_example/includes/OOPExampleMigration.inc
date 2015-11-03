<?php

abstract class OOPExampleMigration extends Migration {
  public function __construct($arguments = array()) {
    // Always call the parent constructor first for basic setup
    parent::__construct($arguments);

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    $this->team = array(
      new MigrateTeamMember('James Candan', 'james@codej.us', t('Engineer')),
    );
  }
}