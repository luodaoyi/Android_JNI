package com.example.jnidemo2;

import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("hello");
    }

    private String ReflectionField = "Reflection Field";
    private static String StaticReflectionField = "Static Reflection Field";

    private native String get_reflection_field();

    private native String get_static_reflection_field();

    private native void set_reflection_field(String value);

    private native void set_static_reflection_field(String value);

    private native String CallMethod(String watermark);

    private native String CallStaticMethod(String watermark);

    private static String StaticDemoMethod(String str) {
        return "Static Call End" + str + "\r\n";
    }

    private String DemoMethod(String str) {
        return "Call End" + str + "\r\n";
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //首先获取字段
        String debug_string = "----------获取字段\r\n";
        debug_string += "1:普通字段=>" + get_reflection_field() + "\r\n";
        debug_string += "2:静态字段=>" + get_static_reflection_field() + "\r\n";

//        Toast.makeText(MainActivity.this, "1:普通字段=>" + get_reflection_field(), Toast.LENGTH_LONG).show();
//        Toast.makeText(MainActivity.this, "2:静态字段=>" + get_static_reflection_field(), Toast.LENGTH_LONG).show();

        //设置字段
        set_reflection_field("Setting Reflection Field");
        set_static_reflection_field("Setting Static Reflection Field");

        debug_string += "---------------设置字段\r\n";
        debug_string += "3:普通字段=>" + ReflectionField + "\r\n";
        debug_string += "4:静态字段=>" + StaticReflectionField + "\r\n";

//        Toast.makeText(this, "3:普通字段=>" + ReflectionField, Toast.LENGTH_LONG).show();
//        Toast.makeText(this, "4:静态字段=>" + StaticReflectionField, Toast.LENGTH_LONG).show();

        debug_string += "----------------jni调用 \r\n";
        debug_string += CallMethod("JNI_MARK ");
        debug_string += CallStaticMethod("JNI_STATIC_MARK");
        TextView txtOutputDebug = (TextView) findViewById(R.id.TextViewDebug);
        txtOutputDebug.setText(debug_string);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
