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
?>
<div id="client-prompt">
<i class='fa fa-info-circle'></i>  &nbsp; <a href="client.php">安装客户端工具</a>
</div>

<div class="topbar">
  <div class="topbar-button" id="top-home"><i class="fa fa-home"></i> 首页</div>
  <div class="topbar-button" id="top-rank"><i class="fa fa-flag"></i> 榜单</div>
  <div class="topbar-button" id="top-category"><i class="fa fa-delicious"></i> 分类</div>
  <div class="topbar-button" id="top-my"><i class="fa fa-user-circle"></i> 我的<span class="update-circle">0</span></div>

  <!-- 隐藏一个刷新按钮 --!>
  <input type="button" class="invisible-button" onclick="javascript: window.location.reload();" value="">
  <input type="hidden" id="os_id" value="">
  <input id="searchText" class="input-thin" type="text" value="搜索应用..." />
</div>

<br/>
<br/>
<br/>
<br/>

<script type="text/javascript" src="../js/top.js"></script>
