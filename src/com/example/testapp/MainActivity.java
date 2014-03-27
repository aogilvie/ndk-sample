package com.example.testapp;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.content.res.AssetManager;

public class MainActivity extends Activity {

	public static AssetManager assetManager;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		assetManager = getResources().getAssets();
		
		nativeMyFunction("Hello world", assetManager);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	public native void nativeMyFunction(String message, AssetManager mgr);
	
	static {
	    System.loadLibrary("testLib");
	}
}

