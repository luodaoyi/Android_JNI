package com.example.jniregisterdynamic;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private native int add(int a, int b);

    private native int sub(int a, int b);

    private native int mul(int a, int b);

    private native int div(int a, int b);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
//        TextView tv = findViewById(R.id.sample_text);
//        tv.setText("add" + add(1, 6) + " sub" + sub(10, 3) + " mul" + mul(3, 6) + " div" + div(9, 3));

//        tv.setText(stringFromJNI());
        Button btn_add = (Button) findViewById(R.id.btn_add);
        Button btn_sub = (Button) findViewById(R.id.btn_sub);
        Button btn_mul = (Button) findViewById(R.id.btn_mul);
        Button btn_div = (Button) findViewById(R.id.btn_div);

        View.OnClickListener ocl = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EditText editA = (EditText) findViewById(R.id.editA);
                int nA = Integer.parseInt(editA.getText().toString());
                EditText editB = (EditText) findViewById(R.id.editB);
                int nB = Integer.parseInt(editB.getText().toString());
                TextView tv = findViewById(R.id.text_value);
                switch (v.getId()) {
                    case R.id.btn_add:
                        tv.setText("" + add(nA, nB));
                        break;
                    case R.id.btn_sub:
                        tv.setText("" + sub(nA, nB));
                        break;
                    case R.id.btn_mul:
                        tv.setText("" + mul(nA, nB));
                        break;
                    case R.id.btn_div:
                        tv.setText("" + div(nA, nB));
                        break;
                }
            }
        };
        btn_add.setOnClickListener(ocl);
        btn_sub.setOnClickListener(ocl);
        btn_mul.setOnClickListener(ocl);
        btn_div.setOnClickListener(ocl);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
