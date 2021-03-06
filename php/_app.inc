<?php

include_once('_db.inc');
include_once('_util.inc');
include_once('_vendor_login.inc');
include_once('_vendor.inc');
include_once('_admin.inc');

function app_version_compare($local_version, $server_version)
{
  $lv = explode(".", $local_version);
  $sv = explode(".", $server_version);

  $i = 0;
  while ($i < count($lv) && $i < count($sv))
  {
    if (intval($lv[$i]) < intval($sv[$i]))
      return -1;
    if (intval($lv[$i]) > intval($sv[$i]))
      return 1;
    $i++;
  }

  if ($i < count($lv))
    return 1;
  if ($i < count($sv))
    return -1;

  return 0;
}

function get_app_icon_file_by_id($id)
{
global $conn;
  $sql = "select icon_file from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_screen_file_by_id($id, $index)
{
  return $id . "_" . $index . ".png";
}

function get_app_file_by_id($id, $os_id, $app_version)
{
global $conn;
  $sql = "select filename from app_file "
         . "  where id=${id} and version='${app_version}' and os_id=${os_id} ";
  return db_get_one_value($sql);
}

function get_app_md5_by_id($id, $os_id, $app_version)
{
global $conn;
  $sql = "select md5 from app_file "
         . "  where id=${id} and version='${app_version}' and os_id=${os_id} ";
  return db_get_one_value($sql);
}


function get_app_install_script_by_id($id, $os_id, $app_version)
{
global $conn;
  $sql = "select install_script from app_file "
         . "  where id=${id} and version='${app_version}' and os_id=${os_id} ";
  return db_get_one_value($sql);
}

function get_app_uninstall_script($id, $os_id)
{
global $conn;
  $version_array = array_values(get_app_file_version_status($id, $os_id));
  $version = $version_array[0][0];
  $sql = "select uninstall_script from app_file "
         . "  where id=${id} and version='${version}' and os_id =${os_id} ";
  return db_get_one_value($sql);
}

function get_app_icon_html($id)
{
  return  "<img id='${id}' src='getAppIcon.php?id=${id}'  width='64' height='64' alt='' border='0' /> \n";
}

function get_app_name($id)
{
global $conn;
  $sql = "select name from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_vendor($id)
{
global $conn;
  $sql = "select vendor_name from app, vendor "
         . "  where app.vendor_id=vendor.id and app.id=${id} ";
  return db_get_one_value($sql);
}

function get_app_category_id($id)
{
global $conn;
  $sql = "select category_id from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_file_status_count($id, $status)
{
global $conn;
  $sql = "select count(1) from app_file "
	. " where id = ${id} and status = '${status}'";
  return db_get_one_value($sql);
}

function get_app_file_version_status($id, $os_id)
{
global $conn;
  $sql = "select version,status from app_file "
         . "  where id = ${id} and os_id = ${os_id} and status = 'published' order by version_unified desc limit 1";
  return db_get_two_columns($sql);
}

function get_app_download_size($id, $app_version, $os_id)
{
global $conn;
  $sql = "select download_size from app_file "
         . "  where id=${id} and version='${app_version}' and os_id=${os_id} ";
  return db_get_one_value($sql);
}

function get_app_os_and_version($app_id)
{
global $conn;
  $sql ="select c.id, c.name, a.version, a.download_size"
                . " from app_file a "
                . " left join os c on a.os_id = c.id"
                . " where a.id = ${app_id} "
                . " and (a.version_unified, a.os_id) "
                . "  in (select max(b.version_unified), b.os_id from app_file b where b.id = ${app_id} and b.status = 'published' group by b.os_id)";
  return db_get_four_columns($sql);
}

function get_app_os_and_version_html($app_id, $os_id)
{
  $html = "";
  $os_version_array = get_app_os_and_version($app_id);

  foreach ($os_version_array as $os_version)
  {
    $html = $html . get_os_version_one_html($os_version, $os_id);
  };

  return $html;
}

function get_os_version_one_html($os_version, $os_id)
{
  $top_class = "";
  $foot_class = "";
  if($os_id != $os_version[0])
  {
    $top_class = "app-os-version-top app-not-this-os-version-color";
    $foot_class = "app-os-version-foot app-not-this-os-version-foot-color";
  }
  else
  {
    $top_class = "app-os-version-top app-this-os-version-color";
    $foot_class = "app-os-version-foot app-this-os-version-foot-color";
  }
    $html = " <div class='app-os-version-css'> \n"
	. "<div class='${top_class}'>${os_version[1]}</div> \n"
	. "<div class='${foot_class}'>${os_version[2]}(${os_version[3]})</div> \n"
	. "</div> \n";

  return $html;
}

function get_app_description($id)
{
global $conn;
  $sql = "select description from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_longdesc($id)
{
global $conn;
  $sql = "select longdesc from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_download_count($id)
{
global $conn;
  $sql = "select download_count from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_count($id)
{
global $conn;
  $vendor_id = get_current_vendor();
  $sql = "select count(1) from app "
	. "where id=${id} and vendor_id=${vendor_id}";
  return db_get_one_value($sql);
}

/*
 * 查询该系统是否有应用使用
 */
function get_app_file_os_id_count($os_id)
{
global $conn;
  $sql = "select count(1) from app_file "
	. " where os_id = ${os_id}";
  return db_get_one_value($sql);
}

function get_app_status_text($status)
{
  switch($status)
  {
    case "published": return "通过审核";
    case "under_review":return "待审核";
    case "rejected":return "未通过审核";
    case "off_the_shelf":return "已下架";
  }
  return "错误状态";
}

function app_inc_download_count($id)
{
global $conn;
  $count = get_app_download_count($id);
  $count ++;
  $sql = "update app set download_count=${count} "
         . "  where id=${id}";
  return db_exec($sql);
}

function get_app_screen_file_count($id)
{
global $conn;
  $sql = "select screen_file_count from app "
         . "  where id=${id}";
  return db_get_one_value($sql);
}

function get_app_card_html($id, $status = "not-defined", $os_id = "")
{
  $name = get_app_name($id);
  $vendor = get_app_vendor($id);
  $download_count = get_app_download_count($id);
  $description = get_app_description($id);
  $icon_img = get_app_icon_html($id);
  $status_html = "";
  $uninstall_html = "";

  $status_html = get_app_status_icon_html($id, $status);
  if ($status == "installed" || $status == "need-updated")
    $uninstall_html = "<span id='${id}' class='uninstall-button'>X</span>";

  $app_version_html = "";
  if ($os_id != "") {
    $version_array = array_values(get_app_file_version_status($id, $os_id));
    $version = $version_array[0][0];
    $uninstall_script = get_app_uninstall_script($id, $os_id);
    $app_version_html = "<input type='hidden' id='app_version' value='${version}'> \n"
			. "<input type='hidden' id='app_uninstall_script' value='${uninstall_script}'> \n";
  } else {
    $app_version_html = "<input type='hidden' id='app_version' value=''> \n";
  }
  $html = "<span class='app-text'> \n"
        . "<p class='app-title'> ${name} </p> \n"
        . "<p class='app-info'> ${vendor} </p> \n"
        . "<p class='app-info'>${download_count}下载</p> \n"
        . "</span>\n"
        . "<input type='hidden' id='app_name' value='${name}'> \n"
        . $app_version_html;
  $desc = "<span class='app-desc'> ${description} </span> \n";
  return "<div id='${id}' class='app-card'> ${icon_img} ${html} ${desc} ${status_html} ${uninstall_html} </div> \n";
}

/*
 * 界面展示
 */

function get_app_screen_file_html($id)
{
  $html = "";

  $count = get_app_screen_file_count($id);
  if ($count == 0)
    return "没有提交界面展示图片";

  for ($i = 0; $i < $count; $i++)
  {
    $img = "<img class='screen-file' id='${id}' src='getAppScreenFile.php?id=${id}&index=${i}'  alt=''/> \n";
    $html = $html . $img;
  }
  return $html;
}

/*
 * 需要升级：在卡片上显示红点
 */

/* 
 * 在应用卡片的右上角显示状态图标
 * 8种状态：
 *   "not-installed" - 未安装，
 *   "installed" 已安装，且最新
 *   "need-updated": 已安装，有升级版本
 *   "downloading": 下载中
 *   "checking-download-file": 检查下载文件
 *   "checking-download-file-error": 检查下载文件错误
 *   "installing": 安装中
 *   "install-error": 安装错误
 *   "uninstalling": 卸载中
 *   "uninstalling-error": 卸载错误
 */

function app_get_status_short_text($status)
{
  switch($status)
  {
    case "not-installed": return "未安装";
    case "installed": return "已安装";
    case "need-updated": return "有升级";
    case "downloading": return "下载中";
    case "checking-download-file": return "检查中";
    case "checking-download-file-error": return "下载错误";
    case "installing": return "安装中";
    case "install-error": return "安装错误";
    case "uninstalling": return "卸载中";
    case "uninstalling-error": return "卸载错误";
  }
  return "错误状态";
}

function get_app_status_icon_html($id, $status)
{
  $text = app_get_status_short_text($status);

  return "<span id='app-icon' class='${status}'>${text}</span>";
}

/*
 * 获取开发者应用页面数据
 */
function get_vendor_list()
{
  $html = "";
  
  foreach (get_vendor_all_id() as $vendor_id)
  {
    $html = $html . get_vendor_one_html($vendor_id);
  }
  return $html;
}

/*
 * 组装 开发者应用页面 列表 html
 */
function get_vendor_one_html($vendor_id)
{
  $login_name = get_vendor_login_name($vendor_id);
  $vendor_name = get_vendor_name($vendor_id);
  $email = get_vendor_email($vendor_id);
  $time = get_vendor_regtime($vendor_id);
  $isActive = get_vendor_isActive($vendor_id);
  $class = "";  
  $button_name = "";
  if($isActive == 1){
    $class = "btn-danger";
    $button_name = "停用";
  } else {
    $class = "btn-success";
    $button_name = "激活";
  }
  $html = "<tr> \n"
	. " <td>${vendor_id}</td> \n"
	. " <td>${login_name}</td> \n"
	. " <td>${vendor_name}</td> \n"
	. " <td>${email}</td> \n"
	. " <td>${time}</td> \n"
	. " <td id='button_$vendor_id'><button type='button' class='btn ${class}' onclick='updateVendorIsActive($vendor_id, $isActive)'>${button_name}</button></td> \n";
  return $html;
}

/*
 * 修改 vendor 表状态
 */
function modify_vendor_isActive($vendor_id, $isActive)
{
  $admin_id = get_current_admin();
  if ($admin_id != "") {
    update_vendor_isActive($vendor_id, $isActive);
    return $isActive;
  } else {
    return $isActive;
  }
}

function set_app_file_status($id, $status, $version,$os_id)
{
global $conn;
  $sql = "update app_file set status='${status}' "
         . "  where id=${id} and version='${version}' and os_id='${os_id}'";
  return db_exec($sql);
}
function update_app_isonline_by_id($id)
{
global $conn;
  $sql = "update app set is_online=1 "
         . "  where id=${id}  ";
  return db_exec($sql);

}
function update_app_appfile_review($appid,$versionreview,$is_admin,$operator,$status,$comment,$date_time,$operation_type,$os_idreview)
{
  try{
    if($operation_type == "pass" ) {
      set_app_file_status($appid, $status,$versionreview,$os_idreview);
      insert_review($appid,$versionreview,$is_admin,$operator,$status,$comment,$date_time);
    }else if($operation_type == "not_pass" ) {
      set_app_file_status($appid, $status,$versionreview,$os_idreview);
      insert_review($appid,$versionreview,$is_admin,$operator,$status,$comment,$date_time);
    }else if($operation_type == "off_the_shelf" ) {
      insert_review($appid,$versionreview,$is_admin,$operator,$status,$comment,$date_time);
      update_app_isonline_by_id($appid);
    }
  echo "true";
  }catch(Exception $e) {   
    echo "false";   
    exit();   
  }   
}
function get_app_file_by_id_version($id,$version,$os_id)
{
global $conn;
  $sql = "select filename from app_file "
         . "  where id=${id} and version='${version}' and os_id=${os_id} ";
  return db_get_one_value($sql);
}

/*
 * 拆分版本号，重新组装，每段补全成5位
 */
function set_app_file_version_unified($version)
{
  $version_arr = explode(".",$version);
  $version_unified = "";
  foreach ($version_arr as $version_subString) {
    $version_unified = $version_unified . sprintf('%05s', $version_subString);
  }
  for ($i = 0; $i < (5 - count($version_arr)); $i++) {
    $version_unified = $version_unified . "00000";
  }
  return $version_unified;
}

function get_app_file_version($app_id, $os_id)
{
  $version_status = array_values(get_app_file_version_status($app_id, $os_id));
  if (is_empty($version_status))
    return "";
  else
    return $version_status[0][0];
}

?>
