#ifndef CONFIG_H
#define CONFIG_H

class Config {

	Config() {};

public:
	// すべてのファイルを同一の日時に変更する
	// ファイルごとに別々の日時に変更する
	 static bool IsAllFileProp;

	 // フォルダーの日時を変更する
	 static bool IsTransformFolderAlso;

	 // フォルダー内のファイルの日時も変更する
	 static bool IsTransformRecursion;

	 // 作成日時(&C)
	 static bool IsCreateDateTimeTransform;
	 static bool IsCreateDateTimeUseCreate;
	 static bool IsCreateDateTimeUseUpdate;
	 static bool IsCreateDateTimeUseAccess;

	 // 更新日時(&U)
	 static bool IsUpdateDateTimeTransform;
	 static bool IsUpdateDateTimeUseUpdate;
	 static bool IsUpdateDateTimeUseCreate;
	 static bool IsUpdateDateTimeUseAccess;

	 // ｱｸｾｽ日時(&E)
	 static bool IsAccessDateTimeTransform;
	 static bool IsAccessDateTimeUseAccess;
	 static bool IsAccessDateTimeUseCreate;
	 static bool IsAccessDateTimeUseUpdate;
};

bool Config::IsAllFileProp = true;

bool Config::IsTransformFolderAlso = true;

bool Config::IsTransformRecursion = false;

bool Config::IsCreateDateTimeTransform = true;
bool Config::IsCreateDateTimeUseCreate = true;
bool Config::IsCreateDateTimeUseUpdate = false;
bool Config::IsCreateDateTimeUseAccess = false;

bool Config::IsUpdateDateTimeTransform = true;
bool Config::IsUpdateDateTimeUseUpdate = true;
bool Config::IsUpdateDateTimeUseCreate = false;
bool Config::IsUpdateDateTimeUseAccess = false;

bool Config::IsAccessDateTimeTransform = true;
bool Config::IsAccessDateTimeUseAccess = true;
bool Config::IsAccessDateTimeUseCreate = false;
bool Config::IsAccessDateTimeUseUpdate = false;

#endif // CONFIG_H