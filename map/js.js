var mapContainer = document.getElementById('map'), // 지도를 표시할 div 
mapOption = { 
    center: new kakao.maps.LatLng(36.2253017, 127.6460516), // 지도의 중심좌표
    level: 13 // 지도의 확대 레벨
};

var map = new kakao.maps.Map(mapContainer, mapOption);

var clusterer = new kakao.maps.MarkerClusterer({
    map: map,
    gridSize: 50,
    averageCenter: true,
    minLevel: 6,
    disableClickZoom: true,
    styles: [{
        width : '53px', height : '52px',
        background: 'url("/cluster.png") no-repeat',
        backgroundSize: "cover",
        color: '#fff',
        textAlign: 'center',
        lineHeight: '54px',
    }]
});

$.ajax({
    url: "/university.json",
    type: "get",
    dataType: "json",
    async: true,
    success: function(result) {
        var imageSrc = "https://t1.daumcdn.net/localimg/localimages/07/mapapidoc/markerStar.png"; 
        var imageSize = new kakao.maps.Size(24, 35); 
        var markerImage = new kakao.maps.MarkerImage(imageSrc, imageSize); 
        var markers = [];

        result.forEach(function(school, index) {
            let position = new kakao.maps.LatLng(school["위도"], school["경도"]);
            let title = school["학교명"];
            let url = school["학교홈페이지"];
            let zipcode = school["우편번호"];
            let address = school["도로명주소"];

            // URL이 http 또는 https로 시작하지 않으면 자동으로 https:// 추가
            let fixedUrl = url.startsWith("http") ? url : `https://${url}`;

            // 마커 생성
            var marker = new kakao.maps.Marker({
                map: map, // 마커를 표시할 지도
                position: position, // 마커를 표시할 위치
                title: title, // 마커의 타이틀, 마커에 마우스를 올리면 타이틀이 표시됩니다
                image: markerImage, // 마커 이미지
                clickable: true // 마커를 클릭했으 때 지도의 클릭 이벤트가 발생하지 않도록 설정합니다
            });

            // 마커가 지도 위에 표시되도록 설정합니다 
            marker.setMap(map);

            // 인포윈도우 콘텐츠 (초기 iframe 숨김)
            var infowindowContent = `<div id="infoWindow-${index}" style="padding: 10px; width: 500px;">
                    <div style="font-size: 15px; font-weight: bold;">${title}</div>
                    <div style="font-size: 12px; margin-bottom: 5px;">${zipcode} ${address}</div>
                    <div style="margin-top: 3px;">
                        <a href="javascript:void(0);" onclick="showPreview(${index}, '${fixedUrl}')" 
                            style="color: blue; text-decoration: none;">
                            미리보기
                        </a>
                    <div style="font-size: 12px; margin-top: 5px;">
                        <a href="${fixedUrl}" target="_blank" style="color: blue; text-decoration: none;">
                            ${url}</div>
                        </a>
                    </div>
                    <div id="preview-${index}" style="display: none; margin-top: 10px;">
                        <iframe id="iframe-${index}" width="100%" height="400px" style="border: none;"></iframe>
                        <button onclick="hidePreview(${index})" style="margin-top: 5px; cursor: pointer;">
                            닫기
                        </button>
                    </div>
                </div>`;

            var infowindow = new kakao.maps.InfoWindow({
                content: infowindowContent,
                removable: true
            });

            // 마커에 클릭 이벤트 등록
            kakao.maps.event.addListener(marker, 'click', function() {
                // 마커 위에 인포윈도우를 표시합니다. 두번째 파라미터인 marker를 넣어주지 않으면 지도 위에 표시됩니다.
                infowindow.open(map, marker);
            });

            markers.push(marker);
        });

        // 클러스터에 마커 추가
        clusterer.addMarkers(markers);
    }
});

// 홈페이지 미리보기 표시 함수
function showPreview(index, url) {
    document.getElementById(`iframe-${index}`).src = url; // iframe에 URL 설정
    document.getElementById(`preview-${index}`).style.display = "block"; // iframe 보이기
}

// 홈페이지 미리보기 닫기 함수
function hidePreview(index) {
    document.getElementById(`preview-${index}`).style.display = "none"; // iframe 숨기기
    document.getElementById(`iframe-${index}`).src = ""; // iframe URL 초기화 (리소스 절약)
}


// 지도 컨트롤 추가
var mapTypeControl = new kakao.maps.MapTypeControl();

// 지도에 컨트롤을 추가해야 지도위에 표시됩니다
// kakao.maps.ControlPosition은 컨트롤이 표시될 위치를 정의하는데 TOPRIGHT는 오른쪽 위를 의미합니다
map.addControl(mapTypeControl, kakao.maps.ControlPosition.TOPRIGHT);

// 지도 확대 축소를 제어할 수 있는 줌 컨트롤을 생성합니다
var zoomControl = new kakao.maps.ZoomControl();
map.addControl(zoomControl, kakao.maps.ControlPosition.RIGHT);

// 클러스터 클릭 시 확대
kakao.maps.event.addListener(clusterer, 'clusterclick', function(cluster) {

    // 현재 지도 레벨에서 1레벨 확대한 레벨
    var level = map.getLevel() - 3;
    // 지도를 클릭된 클러스터의 마커의 위치를 기준으로 확대합니다
    map.setLevel(level, { anchor: cluster.getCenter() });
});