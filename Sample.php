<?php
      echo 'read all<br>';
      $handle = popen('probe', 'r');
      $read = fread($handle, 2096);
      echo $read;
      pclose($handle);
      echo '<br>';
      echo 'read cpu<br>';
      $handle = popen('probe cpu', 'r');
      $read = fread($handle, 2096);
      echo $read;
      pclose($handle);
      echo '<br>';
      echo 'read memory<br>';
      $handle = popen('probe memory', 'r');
      $read = fread($handle, 2096);
      echo $read;
      pclose($handle);
