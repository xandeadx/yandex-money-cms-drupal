<?php
/**
 * @return array
 */
function yamoney_admin_settings() {
	$form = array();

	// General settings
	$form['yamoney_all'] = array(
		'#type' => 'fieldset',
		'#title' => t('Base options'),
		'#description' => t('Любое использование Вами программы означает полное и безоговорочное принятие Вами условий лицензионного договора, размещенного по адресу <a href="https://money.yandex.ru/doc.xml?id=527132">https://money.yandex.ru/doc.xml?id=527132</a> (далее – «Лицензионный договор»). Если Вы не принимаете условия Лицензионного договора в полном объёме, Вы не имеете права использовать программу в каких-либо целях.')
	);
	$form['yamoney_all']['yamoney_ip'] = array(
		'#type' => 'textarea',
		'#title' => t('Allowed IPs for callbacks'),
		'#default_value' => variable_get('yamoney_ip', '0.0.0.0'),
		'#description' => t('The list of IP addresses which has access to payment callbacks. One per line.<br/>0.0.0.0 means allow from all.')
	);
	$form['yamoney_all']['yamoney_mode'] = array(
		'#type' => 'select',
		'#title' => t('Payment mode'),
		'#options' => array(
			'test' => t('Test mode'),
			'live' => t('Live mode')
		),
		'#default_value' => variable_get('yamoney_mode', 'test'),
	);

	$paymode_states = array(
		'invisible' => array(
			':input[name="yamoney_paymode"]' => array('value' => 'kassa'),
		),
	);
	$form['yamoney_all']['yamoney_paymode'] = array(
		'#type' => 'select',
		'#title' => t('Payments mode'),
		'#options' => array(
			'kassa' => t('Kassa mode'),
			'shop' => t('Shop mode')
		),
		'#default_value' => variable_get('yamoney_paymode', 'kassa'),
	);
	$form['yamoney_all']['yamoney_paylogo'] = array(
		'#type' => 'checkbox',
		'#title' => t('Use logo of payment button'),
		'#default_value' => variable_get('yamoney_paylogo', 1),
		'#states' => array(
			'invisible' => array(
				':input[name="yamoney_paymode"]' => array('value' => 'shop'),
			),
		),
	);
	$form['yamoney_all']['yamoney_payment_method'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Enabled payment methods'),
		'#options' => yamoney_get_payment_methods(),
		'#default_value' => variable_get('yamoney_payment_method', array_keys(yamoney_get_payment_methods())),
		'#states' => $paymode_states,
	);

	$form['yamoney_all']['yamoney_default_payment_method'] = array(
		'#type' => 'radios',
		'#title' => t('Default payment method'),
		'#options' => yamoney_get_payment_methods(),
		'#default_value' => variable_get('yamoney_default_payment_method', YAMONEY_DEFAULT_PAYMENT_METHOD),
		'#states' => $paymode_states,
	);

	// Shop settings
	$shop_states = array(
		'invisible' => array(
			':input[name="yamoney_shop"]' => array('checked' => FALSE),
		),
	);
	$p2p_states = array(
		'invisible' => array(
			':input[name="yamoney_shop"]' => array('checked' => TRUE),
		),
	);
	$form['yamoney_shop_setting'] = array(
		'#type' => 'fieldset',
		'#title' => t('Yandex shop settings'),
	);
	$form['yamoney_shop_setting']['yamoney_shop'] = array(
		'#type' => 'checkbox',
		'#title' => t('Select if you have a shop in Yandex.Money'),
		'#default_value' => variable_get('yamoney_shop', 0),
	);
	$form['yamoney_shop_setting']['yamoney_shop_id'] = array(
		'#type' => 'textfield',
		'#title' => t('Shop ID'),
		'#description' => t('You shop ID. If you have any shops in you Yandex account.'),
		'#default_value' => variable_get('yamoney_shop_id', ''),
		'#size' => 2,
		'#states' => $shop_states,
	);
	$form['yamoney_shop_setting']['yamoney_scid'] = array(
		'#type' => 'textfield',
		'#title' => t('Shop SCID'),
		'#default_value' => variable_get('yamoney_scid', ''),
		'#size' => 5,
		'#states' => $shop_states,
	);
	$form['yamoney_shop_setting']['yamoney_secret'] = array(
		'#type' => 'textfield',
		'#title' => t('Shop security key'),
		'#description' => t('You shop password security key. Not you payment password.'),
		'#default_value' => variable_get('yamoney_secret', ''),
		'#size' => 17,
		'#states' => $shop_states,
	);

	// Purse settings
	$form['yamoney_purse_setting'] = array(
		'#type' => 'fieldset',
		'#title' => t('Yandex purse settings'),
		'#states' => $p2p_states,

	);
	$form['yamoney_purse_setting']['yamoney_receiver'] = array(
		'#type' => 'textfield',
		'#title' => t('Purse number'),
		'#description' => t('Your Yandex.Money purse number.'),
		'#default_value' => variable_get('yamoney_receiver', ''),
		'#size' => 14,
		'#states' => $p2p_states,
	);

	$form['yamoney_purse_setting']['yamoney_formcomment'] = array(
		'#type' => 'textfield',
		'#title' => t('Pay comment'),
		'#description' => t('Your Yandex.Money pay comment.'),
		'#default_value' => variable_get('yamoney_formcomment', ''),
		'#states' => $p2p_states,
	);

	$form['yamoney_texts'] = array(
		'#type' => 'fieldset',
		'#title' => t('Text for success and fail payment pages'),
	);
	$success = variable_get('yamoney_success_text', array('value' => '', 'format' => ''));
	$form['yamoney_texts']['yamoney_success_text'] = array(
		'#type' => 'text_format',
		'#title' => t('Text for success page'),
		'#default_value' => $success['value'] ? $success['value'] : '',
		'#format' => $success['format'] ? $success['format'] : '',
	);
	$fail = variable_get('yamoney_fail_text', array('value' => '', 'format' => ''));
	$form['yamoney_texts']['yamoney_fail_text'] = array(
		'#type' => 'text_format',
		'#title' => t('Text for fail page'),
		'#default_value' => $fail['value'] ? $fail['value'] : '',
		'#format' => $fail['format'] ? $fail['format'] : '',
	);
	$form['#submit'][]='send_statistics';
	return system_settings_form($form);
}
/**
 * @param array $form
 * @param array $form_state
 */
function send_statistics($form, &$form_state) {
	global $base_url;
	$path = drupal_get_path('module', 'yamoney') . '/' . 'yamoney.info';
	$info = drupal_parse_info_file($path);
	$headers = array();
	$headers[] = 'Content-Type: application/x-www-form-urlencoded';
	$form_data=$form_state['input'];
	$array = array(
		'url' => $base_url,
		'cms' => 'drupal',
		'version' => VERSION,
		'ver_mod' => $info['version'],
		'yacms' => false,
		'email' => variable_get('site_mail', ''),
		'shopid' => (isset($form_data['yamoney_shop_id']))?$form_data['yamoney_shop_id']:0,
		'settings' => array(
			'kassa' => (isset($form_data['yamoney_shop']))?true:false,
			'kassa_epl' => (isset($form_data['yamoney_paymode']) && $form_data['yamoney_paymode'] =='kassa')?true:false,
			'p2p' => (isset($form_data['yamoney_shop']))?false:true
		)
	);
	$array_crypt = base64_encode(serialize($array));

	$url = 'https://statcms.yamoney.ru/v2/';
	$curlOpt = array(
		CURLOPT_HEADER => false,
		CURLOPT_RETURNTRANSFER => true,
		CURLOPT_SSL_VERIFYPEER => false,
		CURLOPT_SSL_VERIFYHOST => false,
		CURLINFO_HEADER_OUT => true,
		CURLOPT_POST => true,
	);

	$curlOpt[CURLOPT_HTTPHEADER] = $headers;
	$curlOpt[CURLOPT_POSTFIELDS] = http_build_query(array('data' => $array_crypt, 'lbl'=>1));

	$curl = curl_init($url);
	curl_setopt_array($curl, $curlOpt);
	$rbody = curl_exec($curl);
	$errno = curl_errno($curl);
	$error = curl_error($curl);
	$rcode = curl_getinfo($curl, CURLINFO_HTTP_CODE);
	curl_close($curl);
}
/**
 * @param array $form
 * @param array $form_state
 */
function yamoney_admin_settings_validate($form, &$form_state) {
	$checkboxs = $form_state['values']['yamoney_payment_method'];
	$d = array_count_values(array_values($checkboxs));
	if (count($checkboxs) == $d['0'] && isset($form_state['values']['yamoney_paymode']) && $form_state['values']['yamoney_paymode'] =='shop') {
		form_set_error('yamoney_payment_method', t('You do not choose the type of payment online!'));
	}

	if ($form_state['values']['yamoney_ip']) {
		$ips = explode("\n", $form_state['values']['yamoney_ip']);
		foreach ($ips as $ip) {
			$ip = trim($ip);
			if (empty($ip)) {
				continue;
			}
			if (!filter_var($ip, FILTER_VALIDATE_IP)) {
				form_set_error('yamoney_ip', t('IP is not correct: %ip.<br/>Please insert correct server IP or insert 0.0.0.0 to default!', array(
					'%ip' => $ip,
				)));
			}
		}
	}
}