<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          'P!R*;*bVj|2QtF3xWgF}7[VRAni0Nt]#$iS~pN:V&twPX@1^MNM(IF9-YM AN{>8' );
define( 'SECURE_AUTH_KEY',   'uB,&gU!clq4YV)Cx} i64&31sWhlm/#YrsE@hWc&wuQAAt+|Q~0w.M=n%U?%YJ.P' );
define( 'LOGGED_IN_KEY',     'kiO{yzKkajYROw_du7BPfZ<1B0l;3M2p5ez({HHOAN0.{>=y;h3e?EBFBW8&+5t&' );
define( 'NONCE_KEY',         'hCFEhRCIo?{ 5C5(|GmH+lj2]rX6aai:N`B[jF*_aNHZUvT.~b7N[qI3[sqye>T,' );
define( 'AUTH_SALT',         'CM &Pl+$0z.wrVP).:ko$;+Z{1oUA<XXrv|^/.xwb$Os1Q-42(!e_*W*X22+;l9r' );
define( 'SECURE_AUTH_SALT',  ',P #F>=<bEgQd0My,FS5Xx$tZFgG+,DBS>y_uMEy&[Jc$EE3BUC/DB|,^N@TI[=k' );
define( 'LOGGED_IN_SALT',    '9l[>hY]kD!s.I`2U2V,h#$1Y,!7yhTw>e[%{Ts HLtX[SH7%yNO]ho]poW]qVj}k' );
define( 'NONCE_SALT',        '~|V`iK&P-JM`0[6|trxYTXm*W&:M#lu)tY(@H|y#UpQs=jaV!wI<afDN<fuD]GcU' );
define( 'WP_CACHE_KEY_SALT', '+wNM:2zVDUwdzZjLvL!SelhR_1e5++W>k;4l0zzH?]G#_Q]C9).H^i^rVFVjVQ3v' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', '6379' );
define( 'WP_REDIS_CLIENT', 'phpredis' );
define( 'WP_REDIS_DATABASE', '0' );
/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
