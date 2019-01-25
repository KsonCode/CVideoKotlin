package com.cvideokotlin;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class CActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    private TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_c);
        textView = findViewById(R.id.text);
//        textView.setText(stringFromJNI()+""+stringFromC("fdfd"));
        textView.setText(_test());
    }

    public native String stringFromJNI();

    public native String stringFromC(String msg);

    public native String _test();//第二种方式声明本地接口
}
