#!/bin/sh
name=$1
mkdir ./Contest/$name
touch ./Contest/$name/a.cpp
touch ./Contest/$name/b.cpp
touch ./Contest/$name/c.cpp
touch ./Contest/$name/d.cpp

mkdir ./Contest/$name/.idea
touch ./Contest/$name/.idea/workspace.xml
echo """<?xml version="1.0" encoding="UTF-8"?>
<project version="4">
  <component name="CMakeSettings">
    <configurations>
      <configuration PROFILE_NAME="Debug" ENABLED="true" CONFIG_NAME="Debug" />
    </configurations>
  </component>
  <component name="ChangeListManager">
    <list default="true" id="ead0946a-62d2-4fb7-b145-9b95c646136e" name="Changes" comment="">
    </list>
    <option name="SHOW_DIALOG" value="false" />
    <option name="HIGHLIGHT_CONFLICTS" value="true" />
    <option name="HIGHLIGHT_NON_ACTIVE_CHANGELIST" value="false" />
    <option name="LAST_RESOLUTION" value="IGNORE" />
  </component>
  <component name="ClangdSettings">
    <option name="formatViaClangd" value="false" />
  </component>
  <component name="Git.Settings">
    <option name="RECENT_GIT_ROOT_PATH" value="$PROJECT_DIR$/../.." />
  </component>
  <component name="ProjectColorInfo">{
  &quot;associatedIndex&quot;: 4
}</component>
  <component name="ProjectId" id="2eJNA1j1HSe5zef1YpSYQFKY1Ya" />
  <component name="ProjectViewState">
    <option name="hideEmptyMiddlePackages" value="true" />
    <option name="showLibraryContents" value="true" />
  </component>
  <component name="PropertiesComponent"><![CDATA[{
  "keyToString": {
    "RunOnceActivity.cidr.known.project.marker": "true",
    "WebServerToolWindowFactoryState": "false",
    "cf.first.check.clang-format": "false",
    "cidr.known.project.marker": "true",
    "git-widget-placeholder": "main",
    "vue.rearranger.settings.migration": "true"
  }
}]]></component>
  <component name="RunManager">
    <configuration name="a.cpp" type="CppFileRunConfiguration" factoryName="CppFileRunConfiguration" nameIsGenerated="true" REDIRECT_INPUT="false" ELEVATE="false" USE_EXTERNAL_CONSOLE="false" EMULATE_TERMINAL="false" PASS_PARENT_ENVS_2="true" PROJECT_NAME="abc345" TARGET_NAME="a.cpp" CONFIG_NAME="a.cpp">
      <option name="compilerOptions" value="-std=c++17" />
      <option name="sourceFile" value="a.cpp" />
      <method v="2">
        <option name="com.jetbrains.cidr.cpp.runfile.CppFileBuildBeforeRunTaskProvider$BasicBuildBeforeRunTask" enabled="true" />
      </method>
    </configuration>
  </component>
  <component name="SpellCheckerSettings" RuntimeDictionaries="0" Folders="0" CustomDictionaries="0" DefaultDictionary="application-level" UseSingleDictionary="true" transferred="true" />
  <component name="TaskManager">
    <task active="true" id="Default" summary="Default task">
      <changelist id="ead0946a-62d2-4fb7-b145-9b95c646136e" name="Changes" comment="" />
      <created>1711618573190</created>
      <option name="number" value="Default" />
      <option name="presentableId" value="Default" />
      <updated>1711618573190</updated>
      <workItem from="1711618574471" duration="41000" />
      <workItem from="1711619066498" duration="3000" />
      <workItem from="1711619094620" duration="3000" />
    </task>
    <servers />
  </component>
  <component name="TypeScriptGeneratedFilesManager">
    <option name="version" value="3" />
  </component>
</project>
""" >> .idea/workspace.xml

export PATH=$PATH:/Applications/CLion.app/Contents/MacOS
clion ./Contest/$name