### Java Setup (Processing + Gradle)

→ NICHT `gradle init` benutzen, das erzeugt lib/, org/, test/ und ein package-Statement.

```bash
mkdir -p NAME/src/main/java
cd NAME
git init
```

#### settings.gradle (eine Zeile, Name = Projektordner)
```groovy
rootProject.name = 'NAME'
```

#### build.gradle
```groovy
plugins {
    id 'application'
}

repositories {
    mavenCentral()
}

dependencies {
    implementation 'org.processing:core:4.5.6'
}

application {
    mainClass = 'Main'
}
```

#### Main.java in src/main/java/ (KEIN package-Statement!)

#### Gradle Wrapper + Start
```bash
gradle wrapper
./gradlew run
```

#### Neovim
- Im Ordner öffnen, in dem build.gradle liegt
- Rote Imports am Anfang: warten, dann :LspRestart

#### .gitignore
```gitignore
.gradle/
build/
.classpath
.project
.settings/
bin/
.idea/
*.iml
.vscode/
.DS_Store
```
