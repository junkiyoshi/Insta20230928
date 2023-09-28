#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(1);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofSetColor(16, 16, 16);
	for (int x = -100; x <= 100; x += 5) {

		for (int y = -100; y <= 100; y += 5) {

			vector<glm::vec2> vertices;
			vertices.push_back(glm::vec2(x, y));
			for (int i = 0; i < 120; i++) {

				auto deg = ofMap(ofNoise(vertices.back().x * 0.0008, vertices.back().y * 0.0008 + ofGetFrameNum() * 0.01), 0, 1, -360, 360);
				auto vertex = vertices.back() + glm::vec2(2 * cos(deg * DEG_TO_RAD), 2 * sin(deg * DEG_TO_RAD));
				vertices.push_back(vertex);
			}

			ofNoFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();
		}
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}