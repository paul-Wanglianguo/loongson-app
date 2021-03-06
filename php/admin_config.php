<?php
include_once('vendor_header.php');
include_once('_admin.inc');
include_once('_app.inc');
include_once('admin_top.php');
include_once('_category.inc');
include_once('_config.inc');
?>

<br>
<br>
<br>

<div class="nav nav-tabs">
  <li><a href="admin_comment.php">评论管理</a></li>
  <li><a href="admin_hot.php">热门编辑</a></li>
  <li><a href="admin_app.php">应用审核</a></li>
  <li><a href="admin_vendor.php">开发者管理</a></li>
  <li><a href="admin_category.php">类别管理</a></li>
  <li><a href="admin_os.php">操作系统</a></li>
  <li class="active"><a href="admin_config.php">常规设置</a></li>
</div>

<div class="panel panel-default" id="admin_hot_div">
  <div class="panel-body">
   <form id="mail_set_form" name="mail_set_form" >
    <input type='hidden' id='email_test_token' value="<?= create_new_token('email_session_token') ?>" />
   
    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">邮箱参数配置</span>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">SMTP服务器 : </span>
        <input id="smtpserver" name="smtpserver" type="text" class="form-control" value="<?= get_config("smtpserver")?>"/>
      </div>
    </div>
    
    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">SMTP服务器端口 : </span>
        <input id="smtpserverport" name="smtpserverport" type="text" class="form-control" value="<?= get_config("smtpserverport")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">SMTP服务器的用户邮箱 : </span>
        <input id="smtpusermail" name="smtpusermail" type="text" class="form-control" value="<?= get_config("smtpusermail")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">SMTP服务器的用户帐号 : </span>
        <input id="smtpuser" name="smtpuser" type="text" class="form-control" value="<?= get_config("smtpuser")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">SMTP服务器的用户密码 : </span>
        <input id="smtppass" name="smtppass" type="text" class="form-control" value="<?= get_config("smtppass")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">邮件格式（HTML/TXT) :  </span>
        <input id="mailtype" name="mailtype" type="text" class="form-control" value="<?= get_config("mailtype")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">app_data_url : </span>
        <input id="app_data_url" name="app_data_url" type="text" class="form-control" value="<?= get_config("app_data_url")?>"/>
      </div>
    </div>

    <div>
      <label></label>
      <button class="btn btn-primary" id="mail_set_btn"  name="mail_set_btn"  type="button">保 存</button>
    </div>
  </form> 

  <form id="mail_test_form">
    <div class="form-group">
      <div class="input-group send-test-email-width"> 
        <span class="input-group-addon send-test-email-label-width">测试邮件发送</span>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">收件人</span>
        <input id="email_receiver" name="email_receiver" type="text" class="form-control" autocomplete="off" value="<?= get_config("email_receiver")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">主题</span>
        <input id="email_title" name="email_title" type="text" class="form-control" autocomplete="off" value="<?= get_config("email_title")?>"/>
      </div>
    </div>

    <div class="form-group">
      <div class="input-group send-test-email-width">
        <span class="input-group-addon send-test-email-label-width">内容</span>
        <textarea id="email_body" rows=3  name="email_body" type="text" class="form-control"><?= get_config("email_body")?></textarea>
      </div>
    </div>

    <div>
      <label></label>
      <button class="btn btn-primary" id="mail_test_btn"  name="mail_test_btn"  type="button">发 送</button>
    </div>
  </form>

  </div>
</div>


<?php
  include_once('vendor_footer.php');
?>


