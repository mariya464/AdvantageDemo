Action()
{
	lr_start_transaction("UC02_BuyGoods");

	lr_start_transaction("open_site");

	web_set_sockets_option("SSL_VERSION", "AUTO");

//	web_set_user("ivan1", 
//		lr_unmask("626c4544092659c4f334ae51b9da"), 
//		"18.212.178.84:80");
//
//	web_add_cookie("_ga=GA1.1.1407658141.1651259723; DOMAIN=18.212.178.84");
//
//	web_add_cookie("_gid=GA1.1.1769308473.1651259723; DOMAIN=18.212.178.84");
//
//	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=18.212.178.84");

	web_url("ALL", 
		"URL=http://18.212.178.84/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetAccountConfigurationRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountConfigurationRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountConfigurationRequest");

	web_custom_request("GetAccountConfigurationRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountConfigurationRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_cookie("_gat=1; DOMAIN=18.212.178.84");

	web_revert_auto_header("Origin");

	web_url("categories", 
		"URL=http://18.212.178.84/catalog/api/v1/categories", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("search", 
		"URL=http://18.212.178.84/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open_site",LR_AUTO);

	lr_start_transaction("login");


	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	lr_think_time(27);
	
	web_reg_save_param("UserId",
		"LB/IC=<ns2:userId>",
		"RB/IC=<",
		LAST);
	
	web_reg_save_param("Authorization",
		"LB/IC=<ns2:t_authorization>",
		"RB/IC=<",
		LAST);

//	web_custom_request("AccountLoginRequest", 
//		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLoginRequest", 
//		"Method=OPTIONS", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"Referer=http://18.212.178.84/", 
//		"Snapshot=t6.inf", 
//		"Mode=HTML", 
//		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");
	
	web_reg_find("Text/IC=Login Successful",
		LAST);

	web_custom_request("AccountLoginRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

//	web_add_cookie("JSESSIONID=624EC0DB9E691806555C4A12A298D7C3; DOMAIN=18.212.178.84");

	web_revert_auto_header("Origin");
	
	web_add_header("Authorization",
		"Basic {Authorization}");
	
	web_reg_save_param("SessionId",
		"LB/IC=\"sessionId\":\"",
		"RB/IC=\"",
		LAST);

	web_url("{UserId}", 
		"URL=http://18.212.178.84/order/api/v1/carts/{UserId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("click_mice");
	
	web_reg_find("Text/IC=MICE",
		LAST);

	web_url("products", 
		"URL=http://18.212.178.84/catalog/api/v1/categories/5/products", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("attributes", 
		"URL=http://18.212.178.84/catalog/api/v1/categories/attributes", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_mice",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("selection_mice");

	web_url("27", 
		"URL=http://18.212.178.84/catalog/api/v1/products/27", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("all_data", 
		"URL=http://18.212.178.84/catalog/api/v1/categories/all_data", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_url("products_2", 
		"URL=http://18.212.178.84/catalog/api/v1/categories/5/products", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("selection_mice",LR_AUTO);

	lr_start_transaction("goto_cart");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	lr_think_time(12);
	
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_submit_data("414141", 
		"Action=http://18.212.178.84/order/api/v1/carts/{UserId}/product/27/color/414141?quantity=1", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=sessionId", "Value={SessionId}", ENDITEM, 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetAccountByIdRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountByIdRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdRequest");

	lr_think_time(4);

	web_custom_request("GetAccountByIdRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountByIdRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{UserId}</accountId><base64Token>Basic {Authorization}</base64Token></GetAccountByIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetAccountByIdNewRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountByIdNewRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_custom_request("GetAccountByIdNewRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{UserId}</accountId><base64Token>Basic {Authorization}</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");
	
	web_add_header("Authorization",
		"Basic {Authorization}");
	
	web_reg_find("Text/IC=productsInCart",
		LAST);

	web_url("{UserId}_2", 
		"URL=http://18.212.178.84/order/api/v1/carts/{UserId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_custom_request("shippingcost", 
		"URL=http://18.212.178.84/order/api/v1/shippingcost/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"seaddress\":{\"addressLine1\":\"{address}\",\"addressLine2\":\"\",\"city\":\"{city}\",\"country\":\"{country}\",\"postalCode\":{code},\"state\":\"{region}\"},\"secustomerName\":\"{firstName} {lastName}\",\"secustomerPhone\":\"{phoneNumber}\",\"senumberOfProducts\":1,\"setransactionType\":\"SHIPPING_COST\",\"sessionId\":\"{SessionId}\"}", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetAccountPaymentPreferencesRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");

	web_custom_request("GetAccountPaymentPreferencesRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{UserId}</accountId><base64Token>Basic {Authorization}</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");

	web_url("orderPayment-page.html", 
		"URL=http://18.212.178.84/app/order/views/orderPayment-page.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetCountriesRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetCountriesRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetCountriesRequest");

	web_custom_request("GetCountriesRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("goto_cart",LR_AUTO);

	lr_start_transaction("buy_goods");

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	lr_think_time(17);
	

	web_custom_request("AddSafePayMethodRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AddSafePayMethodRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAddSafePayMethodRequest");
	
	web_reg_find("Text/IC=ns2:reason>SafePay data updated successfully</ns2:reason>",
		LAST);

	web_custom_request("AddSafePayMethodRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AddSafePayMethodRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AddSafePayMethodRequest xmlns=\"com.advantage.online.store.accountservice\"><safePayUsername>{login}</safePayUsername><accountId>{UserId}</accountId><safePayPassword>{password}</safePayPassword><base64Token>Basic {Authorization}</base64Token></"
		"AddSafePayMethodRequest></soap:Body></soap:Envelope>", 
		LAST);
	
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_custom_request("{UserId}_3", 
		"URL=http://18.212.178.84/order/api/v1/orders/users/{UserId}", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"{UserId}\",\"Transaction_Currency\":\"USD\",\"Transaction_CustomerPhone\":\"{phoneNumber}\",\"Transaction_MasterCredit_CVVNumber\":\"\",\"Transaction_MasterCredit_CardNumber\":\"4886\",\"Transaction_MasterCredit_CustomerName\":\"\",\"Transaction_MasterCredit_ExpirationDate\":\"122027\",\"Transaction_PaymentMethod\":\"SafePay\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"{password}\",\""
		"Transaction_SafePay_UserName\":\"{login}\",\"Transaction_TransactionDate\":\"29042022\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"{address}\",\"Shipping_Address_City\":\"{city}\",\"Shipping_Address_CountryCode\":40,\"Shipping_Address_CustomerName\":\"{firstName} {lastName}\",\"Shipping_Address_CustomerPhone\":\"{phoneNumber}\",\"Shipping_Address_PostalCode\":{code},\"Shipping_Address_State\":\"{region}\",\"Shipping_Cost\":15.99,\"Shipping_NumberOfProducts\":1,\""
		"Shipping_TrackingNumber\":0},\"purchasedProducts\":[{\"hexColor\":\"414141\",\"productId\":27,\"quantity\":1,\"hasWarranty\":false}]}", 
		LAST);
	
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_custom_request("{UserId}_4", 
		"URL=http://18.212.178.84/order/api/v1/carts/{UserId}", 
		"Method=DELETE", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("buy_goods",LR_AUTO);

	lr_start_transaction("logout");

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	lr_think_time(10);

	web_custom_request("AccountLogoutRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLogoutRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLogoutRequest");
	
	web_reg_find("Text/IC=Logout Successful",
		LAST);

	web_custom_request("AccountLogoutRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{UserId}</loginUser><base64Token>Basic {Authorization}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);
	lr_end_transaction("UC02_BuyGoods", LR_AUTO);

	return 0;
}