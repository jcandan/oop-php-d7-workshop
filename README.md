# OOP PHP for Beginners Workshop

## Getting started

If you haven't already, read and follow the [Setting Up Cloud9](#setting-up-cloud9) instructions below.

First thing, run the following command:
```sh
$ tutorial/setup me@example.com; source ~/.bashrc;
```

Then right-click on `index.php` in the file tree and hit `Run`

![](https://github.com/jcandan/oop-php-d7-workshop/raw/master/tutorial/img/run-index.gif)

At this point, you may open the working Drupal site by clicking `Preview` at the top, and click the "Pop Out into 
New Window" icon on the right of the address bar for the new browser tab that opens within the IDE.

![](https://github.com/jcandan/oop-php-d7-workshop/raw/master/tutorial/img/preview.gif)


## Building a Migrate module

Generally, when you're working with a library, API, plugin, or module, you'll need to brush up on the implementation 
guidelines provided as part of the documentation for that API (if provided).

1. Assumptions
3. Migrate API
4. Base Migration Class
5. Staff Migration
6. Article Migration

### 1. Assumptions

We're working in an existing module. We assume you know how to build a Drupal 7 module. This one is a Features export 
that gives our Users a First and Last name field.

#### Info File

##### Required Info

```php
name = OOP Example
core = 7.x
package = OOP Workshop
version = 7.x-0.1
```

##### Features info

```php
dependencies[] = features
dependencies[] = text
features[features_api][] = api:2
features[field_base][] = field_user_first_name
features[field_base][] = field_user_last_name
features[field_instance][] = user-user-field_user_first_name
features[field_instance][] = user-user-field_user_last_name
project path = sites/all/modules/custom
```

### 3. Migrate API

Add a new file to our includes list in the info file:

```php
files[] = oop_example.migrate.inc
```

```php
/**
 * Implements hook_migrate_api()
 * @return array
 */
function oop_example_migrate_api () {
  return array();
}
```

```php
  return array(
    'api' => 2,
    'groups' => array(),
    'migrations' => array(),
  );
```

```php
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
    ),
```

### 4. Base Migration Class

Add a new file to our includes list in the info file:

```php
files[] = includes/OOPExampleMigration.inc
```

```php
abstract class OOPExampleMigration extends Migration {

}
```

```php
  public function __construct($arguments = array()) {
    // Always call the parent constructor first for basic setup
    parent::__construct($arguments);
  }
```
#### List Team members

With `migrate_ui` enabled, migration pages will indicate people involved in each migration, with their role 
and contact info. This is accomplished via a `team` property, an array of `MigrateTeamMember` objects.

```php
    $this->team = array(
      new MigrateTeamMember('James Candan', 'james@codej.us', t('Engineer')),
    );
  }
```
`MigrateTeamMember` is found in [team.inc](http://www.drupalcontrib.org/api/drupal/contributions%21migrate%21includes%21team.inc/class/MigrateTeamMember/7)


### 5. Staff Migration

Add a new file to our includes list in the info file:

```php
files[] = includes/OOPExampleUserMigration.inc
```

```php
class OOPExampleUserMigration extends OOPExampleMigration {

}
```

```php
  public function __construct ($args) {
    parent::__construct($args);

    $this->description = t('Import Users from Dover Pictura');
  }
```

```php
    $csv = drupal_get_path('module', 'oop_example') . '/data/staff.csv';

    $columns = array(
      0 => array('ID', t('ID')),
      1 => array('Name', t('Name')),
      2 => array('Email', t('Email')),
    );

    $this->source = new MigrateSourceCSV($csv, $columns, array('header_rows' => 1));
```

```php
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
```

```php
    $this->addFieldMapping('mail', 'Email');
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('field_user_first_name', 'first_name');
    $this->addFieldMapping('field_user_last_name', 'last_name');
```

```php
    $source_fields = array(
      'first_name' => t('First name'),
      'last_name' => t('Last name'),
      'name' => t('Drupal username'),
    );

    $this->source = new MigrateSourceCSV($csv, $columns, array('header_rows' => 1), $source_fields);

    ...
  }

  public function prepareRow($row) {
    $names = explode(" ", $row->Name);
    $row->first_name = array_shift($names);
    $row->last_name = array_pop($names);
    $row->name = strtolower($row->first_name . $row->last_name);
  }
```

```sh
$ drush mreg
$ drush ma oopexampleuser
$ drush ma oopexampleuser | awk '{print $1}'
```

```php
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
```

```php
    $this->addFieldMapping('status')->defaultValue(1);
```

### 6. Article Migration

## <a name="#setting-up-cloud9"></a>Setting Up Cloud9
