# OOP PHP for Beginners Workshop

## Getting started

If you haven't already, read and follow the [Setting Up Cloud9](#setting-up-cloud9) instructions below.

First thing, run the following command:
```
$ tutorial/setup me@example.com
```

Then right-click on `index.php` in the file tree and hit `Run`

![](https://github.com/jcandan/oop-php-d7-workshop/raw/master/tutorial/img/run-index.gif)

At this point, you may open the working Drupal site by clicking `Preview` at the top, and click the "Pop Out into 
New Window" icon on the right of the address bar for the new browser tab that opens within the IDE.

![](https://github.com/jcandan/oop-php-d7-workshop/raw/master/tutorial/img/preview.gif)


## Building a Migrate module

Generally, when you're working with a library, API, plugin, or module, you'll need to brush up on the implementation 
guidelines provided as part of the documentation for that API (if provided).

1. Info file
2. Migrate API
3. Base Migration Class
4. Staff Migration
5. Article Migration

### 1. Info file
### 2. Migrate API

```
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
```

### 3. Base Migration Class

```
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
```

### 4. Staff Migration
### 5. Article Migration

## <a name="#setting-up-cloud9"></a>Setting Up Cloud9
