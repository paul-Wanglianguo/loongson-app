<?php
/*
 * loongson-app - The Loongson Application Community
 * 
 * Copyright (C) 2017 Loongson Technology Corporation Limited
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.
 * If you modify file(s) with this exception, you may extend this exception
 * to your version of the file(s), but you are not obligated to do so.
 * If you do not wish to do so, delete this exception statement from your
 * version.
 * If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 */
  include_once('vendor_header.php');
  include_once('_admin.inc');
?>

<div class="login-form">
  <div class="panel panel-primary">
    <div class="panel-heading"> 
      <h3>管理员登录</h3>
    </div>

    <div class="panel-body">
      <p class="text-warning"> <?= get_admin_login_message() ?> </p>

      <form id="admin_loginform" name="admin_loginform" method="post" action="adminDoLogin.php"  >
        <input type="password" style="position: fixed; top: -999px "/>

        <div class="form-group">
          <label>用户名</label> 
          <input id="loginname" name="loginname" type="text" class="form-control" autocomplete="off" />
        </div>

        <div class="form-group">
          <label>密  码</label> 
          <input id="password" name="password" type="password" class="form-control" autocomplete="off" />
        </div>

        <p>
        <button class="btn btn-primary" id="loginsubmit"  name="loginsubmit"  type="submit">登 录</button>
      </form>
    </div>

    <div class="panel-footer">
    </div>
  </div>

</div>

<?php
  clear_admin_login_message();
?>

<?php
  include_once('vendor_footer.php');
?>
